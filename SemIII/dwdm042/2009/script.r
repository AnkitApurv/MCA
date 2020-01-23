#desc: 
#author: Ankit Apurv
#time: 8:30 AM, 20/09/2019
#args: , return:

library(arules)
library(arulesViz)

??arules
??arules::apriori
??arules::inspect
??arules::sort
??arules::itemFrequency
??arules::read.transactions
??factor
??arulesViz

#1. convert groceries dataset from csv to transactions format
grT <- read.transactions("groceries.csv")

#2. 
apr2 <- apriori(grT, parameter = list(support=0.001, confidence=0.8, target="rules"))
inspect(apr2[1:5])

#3.
apr3 <- apriori(grT, parameter = list(support=0.001, confidence=0.8, maxlen=3, target="rules"))
apr31 <- sort(apr3, by="confidence")
inspect(apr3[1:5])

#4.WRONG
inspect(apr2[1:3], setEnd="bakery")

#5
apr5 <- apriori(grT, parameter = list(support=0.001, confidence=0.8, maxlen=1, target="frequent itemsets"))
apr51 <- sort(apr5, by="count")