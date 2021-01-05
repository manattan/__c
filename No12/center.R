X <- c(runif(5000,0,100),rnorm(5000,100,10))
tsd <- function(X) {sqrt(var(X)*(length(X)-1)/length(X))}
layout(matrix(c(1,2,3,4)),2,2)
hist(X,xlim=c(0,140),freq=F,main="original distribution")
z <- rep(0,1000) #repeat 0 1000 times
for (i in 1:1000) {z[i] <- mean(sample(X,5))}
hist(z,xlim=c(0,140), freq=F)
