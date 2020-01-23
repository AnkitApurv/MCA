#desc: excercise 1
#author: Ankit Apurv
#time: 26/07/19, 8:30-11:30

#args: m and c constants, x variable, return: y
straightLine <- function(m,x,c) {
    y <- (m*x) + c
    return(y)
}

#args: a, return: factorial of a
factorial <- function(a) {
    fac <- 1
    for(i in 1:a) {
        fac <- fac * i
    }
    return(fac)
}

#args: number of elemnts in series, return: fibonacci series
fibonacci <- function(n) {
    fib <- c(0,1)
    for(i in 3:n) {
        j <- fib[i-1] + fib[i-2]
        fib <- append(fib,j,length(fib))
    }
    return(fib)
}