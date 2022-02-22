# Epidemic Simulation

## Models



In class, we simulated an epidemic:

```r
n = 10000  # Number of people.
days = 60  # Days to simulate.
S.init = 9900 # Susceptible
I.init = 100  # Infected initially.
R.init = 0  # Num of recovered.

beta = .4  #Infection
gamma = .2 # Recovery rate

S.t = rep(NA, days)
I.t = rep(NA, days)
R.t = rep(NA, days)

S.t[1] = S.init
I.t[1] = I.init
R.t[1] = R.init



for (i in c(1:(days-1)))
{
  num.infected = rbinom(1, S.t[i]*I.t[i], beta/n)  # For each s,i pair/possible collision. 
  if (num.infected > S.t[i])
  {
    num.infected = S.t[]
  }
  
  num.recovered = rbinom(1, I.t[i], gamma)
  
  S.t[i+1] = S.t[i] - num.infected
  I.t[i+1] = I.t[i] + num.infected - num.recovered
  R.t[i+1] = R.t[i] + num.recovered
}

plot(S.t, type = "l", main = "Number of Susceptibles Over Time", xlab = "day", ylab = "S")
plot(I.t, type = "l", main = "Number of Infected Over Time", xlab = "day", ylab = "I")
plot(R.t, type = "l", main = "Number of Removed Over Time", xlab = "day", ylab = "R")
```

## $$R_0 = \frac{\beta}{y}$$

* More later...

