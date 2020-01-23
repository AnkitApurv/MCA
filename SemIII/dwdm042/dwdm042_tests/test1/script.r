fares <- train$Fare[train$Fare > 0]
lowestFarePerson <- train$PassengerId[min(fares)]
train$Name[train$PassengerId == lowestFarePerson]
train$Ticket[train$PassengerId == lowestFarePerson]
min(fares)

name <- "Andersson, Mr. Anders Johan"
train$SibSp[train$Name == name] + train$Parch[train$Name == name]


mean(train$Fare[train$Pclass == 1])
mean(train$Fare[train$Pclass == 2])
mean(train$Fare[train$Pclass == 3])

boxplot(train$Age ~ train$Survived)

survivingKids <- train$Name[train$Age < 18 & train$Survived == 1]
length(survivingKids)

chisq.test(train$Pclass, train$Survived)


f1 <- train$PassengerId[train$Sex == 'female' & train$Pclass == 1]
m1 <- train$PassengerId[train$Sex == 'male' & train$Pclass == 1]
2F <- train$PassengerId[train$Sex == 'female' & train$Pclass == 2]
2M <- train$PassengerId[train$Sex == 'male' & train$Pclass == 2]
3F <- train$PassengerId[train$Sex == 'female' & train$Pclass == 3]
3M <- train$PassengerId[train$Sex == 'male' & train$Pclass == 3]