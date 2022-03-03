#include <cpuloan.hpp>
#include <eosio.token.hpp>
#include <eosio/system.hpp>
#include <cctype>

ACTION cpuloandz::logstake(name from, time_point_sec unstakeTime, asset stake_value) {
    require_auth(get_self());
    // Init the _message table
    staking_table data(get_self(), get_self().value);
    // Create a message record if it does not exist
    data.emplace(get_self(), [&](auto& msg) {
        msg.key = data.available_primary_key();
        msg.user = from;
        msg.unstakeTime = unstakeTime;
        msg.waxstake = stake_value;
    }); 
}

ACTION cpuloandz::getunstake(){
    require_auth(get_self());
    
    symbol token_symbol("WAX", 8);

    staking_table data(get_self(), get_self().value);
    vector<uint64_t> keysForDeletion;
    // find items which are for the named poll
    for(auto& item : data) {
        if (item.unstakeTime <= current_time_point()) {
         keysForDeletion.push_back(item.key);   
        }
    }
    check(keysForDeletion.size() > 0,"no one have to unstake");
      // now delete each item for that poll
    for (uint64_t key : keysForDeletion) {
        eosio::print("remove from _polls ", key);
        auto itr = data.find(key);
        if (itr != data.end()) {
            action(
            permission_level(get_self(),"active"_n), 
            "eosio"_n, "undelegatebw"_n,
            undelegatebw_args{
                get_self(),
                itr->user,
                asset(0, token_symbol),
                itr->waxstake}
            ).send();
            data.erase(itr);
        }


    }

}

void cpuloandz::deposit(name from, name to, asset quantity, const string &memo){
    auto self = get_self();
    symbol token_symbol("WAX", 8);

    uint64_t day = 3;
    char* end;

    uint64_t stake_value = quantity.amount * 100 / day;

    uint64_t unstakeSeconds = day * 86400;

    if (to == self){
      if(memo.size()){
        check(std::all_of(memo.begin(), memo.end(), ::isdigit),"memo must contains only number");
        auto getDay = stoi(memo);
        print(getDay);
        check(getDay >= 3,"Days must be higher than 2");
        day = getDay;  
      }
      check(quantity.amount > 0, "Insufficient value");
      check(quantity.symbol == token_symbol, "Illegal asset symbol");

      const asset balance = eosio::token::get_balance("eosio.token"_n, self, token_symbol.code());
      check(balance.amount >= stake_value, "not enough balance for stake");

      auto nowWithSeconds = time_point_sec(current_time_point());
      time_point_sec unstakeTime = time_point_sec(nowWithSeconds + unstakeSeconds);


      action(
          permission_level(self,"active"_n),
          get_self(),
          "logstake"_n,
          make_tuple(from,unstakeTime,asset(stake_value, token_symbol))
      ).send();
      action(
          permission_level(self,"active"_n), 
          "eosio"_n, "delegatebw"_n,
          delegatebw_args{
              self,
              from,
              asset(0, token_symbol),
              asset(stake_value, token_symbol),
              false}
        ).send();
    }
}

