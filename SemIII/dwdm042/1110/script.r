#desc: lab 9
#author: Ankit Apurv
#time: 8:30 AM, 11/10/2019

#1 to input two vectors, calculate co-relation co-efficient, visualize co-relation,
# output should indicate whether the vectors were co-related
corviz <- function(x, y) {
    if(is.null(x) | is.null(y)) {
        x <- c(90, 100, 130, 150, 180, 200, 220, 300, 350, 400)
        y <- c(25, 28, 20, 20, 15, 12, 13, 10, 8, 6)
    }
    result <- cor.test(x, y)
    plot(x, y, type="p")
    print(result)
}

#2 function to predict 'y' given 'x' based on least squares method
#incorrect
predictByLeastSquares <- function(x, y, xi) {
    #relation <- lm(x~y)
    #yi <- predict(relation, xi)
    
    meanX <- mean(x)
    meanY <- mean(y)
    
    b1Numerator <- 0
    for (i in 1:length(x)) {
        b1Numerator <- b1Numerator + ((x[i] - meanX) * (y[i] - meanY))
    }
    
    b1Denominator <- 0
    for (i in x) {
        b1Denominator <- b1Denominator + ((i - meanX) ^ 2)
    }
    
    # b1 represents slope in the cartesian plane
    b1 <- b1Numerator / b1Denominator
    # b0 represents xi intercept line in the cartesian plane
    b0 <- meanY - (b1 * meanX)
    
    yi <- b0 + (b1 * xi)
    return(yi)
}

#3 split 'iris' dataset into training and testing, 70:30 split
iris <- read.csv("~/iris.csv")
testDatasetSize <- floor(nrow(iris) * 0.3)
#set.seed(integer) #to ensure non-random, reproducible output from sample
irisTestIndices <- sample(1:nrow(iris), testDatasetSize, replace = FALSE)
irisTest <- iris[irisTestIndices,]
irisTrain <- iris[-irisTestIndices,]

#4 use 'knn' for classification on 'iris' dataset, compute accuracy for each class
#knn
classInfoForTrain <- factor(iris[-irisTestIndices, "class"])
knnk <- 3
irisTrain <- irisTrain[-5]#5 th column is class
irisTest <- irisTest[-5]
irisClassification <- knn(irisTrain, irisTest, classInfoForTrain, knnk)

#confusion matrix
irisTestVerifyFactor <- factor(iris[irisTestIndices, "class"])
expected <- table(irisTestVerifyFactor)
observed <- table(irisClassification)

#accuracy
for(i in 1:nrow(observed)) {
    truePositive <- observed[i] - abs(observed[i] - expected[i])
    falsePositive <- observed[i] - truePositive
    trueNegative <- (testDatasetSize - observed[i]) - abs(observed[i] - expected[i])
    falseNegative <- (testDatasetSize - observed[i]) - trueNegative
    
    sensetivity <- truePositive / expected[i]
    specificity <- trueNegative / (testDatasetSize - observed[i])
    
    accuracy <- (truePositive + trueNegative) / testDatasetSize
    print(accuracy)
}
