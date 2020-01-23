#desc: 
#author: Ankit Apurv
#time: 8:30 AM, 23/10/2019
iris <- read.csv("~/iris.csv")

#remove class column
irisCl <- iris[-5]

#k-means with three cluster centers
#clusterCenters <- matrix(irisCl[row(irisCl) == 1 | row(irisCl) == 51 | row(irisCl) == 101], nrow = 3, ncol = 4)
#kMeansCluster <- kmeans(irisCl, clusterCenters)
kMeansCluster <- kmeans(irisCl, centers = 3)


#visualize in group scatter plot - NOT WORKING
clusterFactor <- factor(kMeansCluster$cluster)
iris$cluster <- clusterFactor
ggplot(iris, mapping = aes(iris$petallength, iris$sepallength))

#simplified ggplot() == qplot() - requires ggplot2
qplot(iris$petallength, iris$petalwidth)

#visualize, simple, needs Princial Compnent Analysis(PCA) or Decision Tree Inductionto reduce dimensions
plot(iris$petallength, iris$sepallength)
plot(iris$petallength, iris$sepalwidth)
plot(iris$petallength, iris$petalwidth)
