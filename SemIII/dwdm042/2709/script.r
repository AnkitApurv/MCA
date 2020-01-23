#desc: 
#author: Ankit Apurv
#time: 8:30 AM, 27/09/2019

#1
genderSurvival <- chisq.test(train$Sex, train$Survived)
genderSurvival[["statistic"]][["X-squared"]]
genderSurvival[["observed"]]

#2
classSurvival <- chisq.test(train$Pclass, train$Survived)
classSurvival[["statistic"]][["X-squared"]]
classSurvival[["observed"]]

#3
#pre-processing
any(is.na(train$Age)) #TRUE, FALSE for the rest of the attribute
#keeping age as is to avoid change in this small dataset
tT <- read.transactions("train.csv", sep = ",", format = "basket", rm.duplicates = FALSE, header = TRUE, cols = 1)

rules <- apriori(tT, parameter = list(target = "rules",maxlen = 11), appearance = list(rhs = c("Survived=0", "Survived=1"), none = c("PassengerId")))