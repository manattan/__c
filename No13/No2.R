dat <- read.delim("./R07.txt")
attach(dat)
spre <- var(pre)
spost <- var(post)
spre
spost
f0 <- spre/spost
p <- 2*(1-pf(f0,14,14))