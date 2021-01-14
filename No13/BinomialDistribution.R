times <- function (n) {
  dice <- as.integer(runif(n,1,21))
  hit <- sum(ifelse(dice<5, 1, 0))
  return(hit)
}

a <- c(4,10,20,50)
layout(matrix(1:4,nr=2))
for (i in 1:4){
  y <- 1:1000
  for (j in 1:1000){
    y[j] <- times(a[i])
  }
  
  barplot(table(y),main=paste("n=", a[i]))
}