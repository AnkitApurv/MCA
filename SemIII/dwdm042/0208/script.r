
#desc: exercise 1
#author:Ankit Apurv
#time:8:30 am

#1 Tabulate number of cylinders in the mtcars dataset table.mtcars$cylinder
tabulate(mtcars$cyl)

#2 Find the five number summary of milespergallon 
summary(mtcars$mpg)

#3 Draw a histogram for hp 
hist(mtcars$hp)

#4 Box plot the miles per gallon 
boxplot(mtcars$mpg)

#5 Find the avg weight of all cars
mean(mtcars$wt)

#6 Find the car with the minimum displacemen
minDisp <- min(mtcars$disp)
rownames(mtcars[mtcars$disp == minDisp,])

#7 Find the car with the maximum qsec
maxQsec <- max(mtcars$qsec)
rownames(mtcars[mtcars$qsec == maxQsec,])

#8 Find the median horse power
median(mtcars$hp)

#9 find the car with the highest fuel efficiency
maxFE <- max(mtcars$mpg)
rownames(mtcars[mtcars$mpg == maxFE,])

#10 Find the car with the lowest fuel efficiency
minFE <- min(mtcars$mpg)
rownames(mtcars[mtcars$mpg == minFE,])

#11 Find the car with the best hp 
maxHP <- max(mtcars$hp)
rownames(mtcars[mtcars$hp == maxHP,])

#12 Tabulate mpg for different number of gears
xtabs(mtcars$mpg ~ mtcars$gear) / table(mtcars$gear)

#13 Do side by side boxplot of mpg for cars with automatic transmission Vs cars with Manual transmission
boxplot(mtcars$mpg ~ mtcars$am)