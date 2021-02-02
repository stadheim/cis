const {Blockchain, Transaction} = require('./blockchain');

let staCoin = new Blockchain();

staCoin.createTransaction(new Transaction('address1','address2',100));
staCoin.createTransaction(new Transaction('address2','address1',50));

console.log("\n Starting the miner...");
staCoin.minePendingTransactions("Siljes-address");
console.log("\nBalance of silje is", staCoin.getBalanceOfAddress("Siljes-address"));

console.log("\n Starting the miner again...");
staCoin.minePendingTransactions("Siljes-address");
console.log("\nBalance of silje is", staCoin.getBalanceOfAddress("Siljes-address"));