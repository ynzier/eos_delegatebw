--- wax Project ---

 - How to Build -
   - cd to 'build' directory
   - run the command 'cmake ..'
   - run the command 'make'

 - After build -
   - The built smart contract is under the 'wax' directory in the 'build' directory
   - You can then do a 'set contract' action with 'cleos' and point in to the './build/wax' directory

 - Additions to CMake should be done to the CMakeLists.txt in the './src' directory and not in the top level CMakeLists.txt

 "PW5JVZKVhg8h19DmkfWhszMR2StmSRrQQB7pGNi6cWv12daJ6tKwH"

 EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV

 "EOS5CngZirZa75LNUqza1QSs6qZBbrNT7kWXNdPhxNsdrWXCuCesL"


 {"msg": "succeeded", "keys": {"active_key": {"public": "EOS5ArD3yE6nuY3sehwtWXmtUyZRusbAyh9KX4NTd25An6nK1JnjN", 
 "private": "5KTjdTZnxXNNah3ZdKW6jQ35qEGxa9qvHtf8mzxKbhFqZhiEKyv"}, 
 "owner_key": {"public": "EOS8AqzGh8R6WXGPjAcYNJt4M9WfiQrjoSbU12vUES9vUq8ovRLw4", 
 "private": "5KfKtcoTGZhc1fXuRLrtjXnUumszMfXhjh6K48YbCyGyxYzJ1on"}}, "account": "wyndazierwdz"}
 PASSWORD "PW5KgWK52GiugrwNH7BbzmWCjKQyGPdzD7K8E9KfS1f1UYDhnc2zU"

{"msg": "succeeded", "keys": {"active_key": {"public": "EOS7BKRF4b5Aff219i1wxNufvTnMtHdozjQLWqR3jKYghmSjqEnSR", 
"private": "5HrH2NHsegDVkriKvywSZKZCSZji6wxwcPwpFGGLrRjApYdWjJB"}, 
"owner_key": {"public": "EOS78zf1cCZ88FzZ2TNFmja1ZK96dhU7LFabccaMnKgS14ZxXYZGy", 
"private": "5JoQEUZJBC9KZAdcwS4uzqWYsKQ47s7eYBPzLfS9yi9k9NoaHVM"}}, "account": "wyndazierwtf"}
PASSWORD "PW5Js8KYeq5SXqWf3i2uHXTsPGvG1kYeCBziFjdAFFRAbTH8KT984"



cleos wallet create -n wyndazierwdz --to-console &&
cleos wallet import -n wyndazierwdz --private-key 5KTjdTZnxXNNah3ZdKW6jQ35qEGxa9qvHtf8mzxKbhFqZhiEKyv &&
 cleos wallet import -n wyndazierwdz --private-key 5KfKtcoTGZhc1fXuRLrtjXnUumszMfXhjh6K48YbCyGyxYzJ1on

cleos wallet create -n wyndazierwtf --to-console &&
cleos wallet import -n wyndazierwtf --private-key 5HrH2NHsegDVkriKvywSZKZCSZji6wxwcPwpFGGLrRjApYdWjJB &&
 cleos wallet import -n wyndazierwtf --private-key 5JoQEUZJBC9KZAdcwS4uzqWYsKQ47s7eYBPzLfS9yi9k9NoaHVM


cleos -u https://testnet.waxsweden.org system buyram wyndazierwdz wyndazierwdz "3.00000000 WAX"
cleos -u https://testnet.waxsweden.org system delegatebw wyndazierwdz wyndazierwdz "4.00000000 WAX" "5.00000000 WAX"

cleos -u https://testnet.waxsweden.org transfer wyndazierwdz wyndazierwdz "1.00000000 WAX" ""


cleos -u https://testnet.waxsweden.org transfer wyndazierwtf wyndazierwdz "1.0000 WAX" "3"


rm -rf ~/eosio-wallet
cleos wallet open -n wyndazierwdz &&
cleos wallet unlock -n wyndazierwdz --password PW5JrvCV1b8MqHsjPGsp4hT1nrP5erWydv2TpPUxYPSy6hw9pzWgh
PW5JFaouDUdN2txzmeysTjphQuhqTqd8yyXfAyY4t8TBkoX3qEW2B

cleos wallet open -n wyndazierwtf &&
cleos wallet unlock -n wyndazierwtf --password PW5KJU7KK1VSaN86Err7bSeAs9Wd4hJ9Y5HD5S4dC9uFAYhZSC3vX
PW5JUYuw1Ji8ksfT4HnSp2fwYiPzccEU2uYwDP9bqCbzNQYNBnecD

"PW5J9stihm6XeFK8MEfQ1AtwQLbcX2EvzMRGWrcqkoH6RKFGCcKkk"

"PW5JJ7YN7CYURLHe3GFGyMqsDgapqwYNVWP6BL6kJQYJgRXzZB5jH"