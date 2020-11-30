#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
int divideTwoIfEven(int x) {
  if(x % 2 == 0) {
    return x/2;
  } else {
    return x;
  }
}

// [[Rcpp::export]]
Rcpp::IntegerVector divideTwoIfEvenVector(Rcpp::IntegerVector x) {
  return sapply(x, divideTwoIfEven);
}

// [[Rcpp::export]]
int addOneIfOdd(int x) {
  if(x % 2 != 0) {
    return x + 1;
  } else {
    return x;
  }
}

// [[Rcpp::export]]
Rcpp::IntegerVector addOneIfOddVector(Rcpp::IntegerVector x) {
  return sapply(x, addOneIfOdd);
}


// [[Rcpp::export]]
int divideTenIfTens(int x){
  if(x % 10 == 0) {
    return x / 10;
  } else {
    return x;
  }
}

// [[Rcpp::export]]
Rcpp::IntegerVector divideTenIfTensVector(Rcpp::IntegerVector x) {
  return sapply(x, divideTenIfTens);
}

/*** R
divideTwoIfEvenVector(seq(1:100))
addOneIfOddVector(seq(1:100))
divideTenIfTensVector(seq(1:100))
*/
