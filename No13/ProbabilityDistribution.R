layout(matrix(1:4,nr=2))

a <- c(4,20,10,50)

for (i in 1:4){
  n <- a[i]
  k <- 0
  chk <- 1:n+1
  while (k <= n){
    chk[k+1]<- choose(n,k)*(0.2^k)*(0.8^(n-k))
    k <- k+1
  }
  barplot(chk,main=paste("n =", n))
}