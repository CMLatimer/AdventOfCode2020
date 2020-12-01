#include <Rcpp.h>
using namespace Rcpp;

// Part 1
// [[Rcpp::export]]
int part1(Rcpp::NumericVector x, int val = 2020){
  x.sort();
  while (x.length() > 2){
    x = x[x <= val - x[0]];
    if(x[0] + x[x.length() - 1] == val){
      Rcpp::NumericVector V = Rcpp::NumericVector {x[0], x[x.length() - 1]};
      return(V[0]*V[1]);
    } else {
      x = x[x > x[0]];
    }
  }
  return 0;
}

// Part 2
// [[Rcpp::export]]
int part2(Rcpp::NumericVector x, int val = 2020){
  x.sort();
  while (x.length() > 3){
    x = x[x <= val - x[1] - x[0]];
    int i = 1;
    while(x.length() - i > 0){
      Rcpp::NumericVector diff = val - x[x.length() - i] - x[0] - x;
      if(any(diff == 0).is_true()){
        Rcpp::NumericVector V = Rcpp::NumericVector {x[0], x[x.length() - i], val - x[x.length() - i] - x[0]};
        return(V[0]*V[1]*V[2]);
      } else {
        i++;
      }
    }
    x = x[x > x[0]];
  }
  return 0;
}

/*** R
data = scan("Day1.txt")
part1(data)
part2(data)

library(microbenchmark)
microbenchmark(part1(data), times = 100000L)
microbenchmark(part2(data), times = 100000L)
*/


