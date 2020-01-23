#desc: cereals dataset
#author:Ankit Apurv
#time:8:30-11:30 am

#1 Tabulate the following attributes: mfr, and type of cereals
table(Cereals$mfr)
table(Cereals$type)

#2 Display the 5 number summary for nutritional attributes from calories to vitamins
summary(Cereals$calories)
summary(Cereals$protein)
summary(Cereals$fat)
summary(Cereals$sodium)
summary(Cereals$fiber)
summary(Cereals$carbo)
summary(Cereals$sugars)
summary(Cereals$potass)
summary(Cereals$vitamins)
summary(subset(Cereals, select = calories:vitamins))

#3 For missing values find and replace with arithmetic mean of the attributes.
Cereals$name[Cereals$carbo == -1] #[1] Quaker_Oatmeal
vecCarbo <- c(Cereals$carbo[Cereals$carbo != -1])
Cereals$carbo[Cereals$carbo == -1] <- mean(vecCarbo)
Cereals$name[Cereals$carbo == -1] #factor(0)

for(i in subset(Cereals, select = calories:vitamins) )
{
  vecI <- c(Cereals$i[Cereals$i != -1])
  Cereals$i[Cereals$i == -1] <- mean(vecI)
}

Cereals$name[Cereals$sugars == -1] #[1] Quaker_Oatmeal
vecSugars <- c(Cereals$sugars[Cereals$sugars != -1])
Cereals$sugars[Cereals$sugars == -1] <- mean(vecSugars)
Cereals$name[Cereals$sugars == -1] #factor(0)

Cereals$name[Cereals$potass == -1] #[1] Almond_Delight         Cream_of_Wheat_(Quick)
vecPotass <- c(Cereals$potass[Cereals$potass != -1])
Cereals$potass[Cereals$potass == -1] <- mean(vecPotass)
Cereals$name[Cereals$potass == -1] #factor(0)


#4 Find and replace outliers with median.
#outliers <- 1.5 * IQR where IQR <- Q3 - Q1
#to find if an attribute has an outlier record

caloriesLB <- summary(Cereals$calories)[2] - (1.5 * IQR(Cereals$calories))
caloriesUB <- summary(Cereals$calories)[5] + (1.5 * IQR(Cereals$calories))
caloriesOOB <- Cereals$name[(Cereals$calories < caloriesLB) | (Cereals$calories > caloriesUB)]
caloriesINB <- Cereals$calories[(Cereals$calories >= caloriesLB) & (Cereals$calories <= caloriesUB)]
Cereals$calories[ Cereals$name[caloriesOOB] ] <- median(caloriesINB)

fiberLB <- summary(Cereals$fiber)[2] - (1.5 * IQR(Cereals$fiber))
fiberUB <- summary(Cereals$fiber)[5] + (1.5 * IQR(Cereals$fiber))
fiberOOB <- Cereals$name[(Cereals$fiber < fiberLB) | (Cereals$fiber > fiberUB)]
fiberINB <- Cereals$fiber[(Cereals$fiber >= fiberLB) & (Cereals$fiber <= fiberUB)]
Cereals$fiber[ Cereals$name[fiberOOB] ] <- median(fiberINB)


for(i in subset(Cereals, select = calories:vitamins) )
{
  LB <- summary(Cereals$i)[2] - (1.5 * IQR(Cereals$i))
  UB <- summary(Cereals$i)[5] + (1.5 * IQR(Cereals$i))
  OOB <- Cereals$name[(Cereals$i < LB) | (Cereals$i > UB)]
  if(!is.null(OOB))
  {
    print(i)
    print(OOB)
    INB <- Cereals$i[(Cereals$i >= LB) & (Cereals$i <= UB)]
    Cereals$i[ Cereals$name[OOB] ] <- median(INB)
  }
}

carboLB <- summary(Cereals$carbo)[2] - (1.5 * IQR(Cereals$carbo))
carboUB <- summary(Cereals$carbo)[5] + (1.5 * IQR(Cereals$carbo))
Cereals$name[(Cereals$carbo < carboLB) | (Cereals$carbo > carboUB)]

sugarsLB <- summary(Cereals$sugars)[2] - (1.5 * IQR(Cereals$sugars))
sugarsUB <- summary(Cereals$sugars)[5] + (1.5 * IQR(Cereals$sugars))
Cereals$name[(Cereals$sugars < sugarsLB) | (Cereals$sugars > sugarsUB)]

potassLB <- summary(Cereals$potass)[2] - (1.5 * IQR(Cereals$potass))
potassUB <- summary(Cereals$potass)[5] + (1.5 * IQR(Cereals$potass))
potassOOB <- Cereals$name[(Cereals$potass < potassLB) | (Cereals$potass > potassUB)]
potassINB <- Cereals$potass[(Cereals$potass >= potassLB) & (Cereals$potass <= potassUB)]
Cereals$potass[ Cereals$name[potassOOB] ] <- median(potassINB)

vitaminsLB <- summary(Cereals$vitamins)[2] - (1.5 * IQR(Cereals$vitamins))
vitaminsUB <- summary(Cereals$vitamins)[5] + (1.5 * IQR(Cereals$vitamins))
vitaminsOOB <- Cereals$name[(Cereals$vitamins < vitaminsLB) | (Cereals$vitamins > vitaminsUB)]
vitaminsINB <- Cereals$vitamins[(Cereals$vitamins >= vitaminsLB) & (Cereals$vitamins <= vitaminsUB)]
Cereals$vitamins[ Cereals$name[vitaminsOOB] ] <- median(vitaminsINB)

#5 Compare the 5 number summary before and after preprocessing.
summary(Cereals$calories)
summary(Cereals$protein)
summary(Cereals$sodium)
summary(Cereals$fiber)
summary(Cereals$carbo)
summary(Cereals$sugars)
summary(Cereals$potass)
summary(Cereals$vitamins)

#6 Draw side-by-side box plots of Calories of Hot Vs cold cereals.
boxplot(Cereals$calories ~ Cereals$type)

#7 Are the attributes calories and consumer rating correlated
chisq.test(Cereals$calories, Cereals$rating)

#8 Are the attributes mfr and consumer rating correlated
chisq.test(Cereals$mfr, Cereals$rating)

#9 Which is the best Vs worst cereal in terms of user rating
Cereals$name[Cereals$rating == max(Cereals$rating)]
Cereals$name[Cereals$rating == min(Cereals$rating)]

#10 Which is the best Vs worst cereal in terms of calories
Cereals$name[Cereals$calories == max(Cereals$calories)]
Cereals$name[Cereals$calories == min(Cereals$calories)]

#11 Rate the top 5 cereals in terms of user rating
rating <- Cereals$name[order(Cereals$rating, decreasing = TRUE)]
rating[1:5]

#12 Identify the cereal with the highest sodium.
Cereals$name[Cereals$sodium == max(Cereals$sodium)]

#13 Identify the cereal with the lowest carbohydrate.
Cereals$name[Cereals$carbo == min(Cereals$carbo)]

#14 Are the variable shelf and sugar correlated?
chisq.test(Cereals$shelf, Cereals$sugars)

#15 Identify the manufacturer of the cereal with the highest sugar content.
Cereals$mfr[Cereals$sugars == max(Cereals$sugars)]