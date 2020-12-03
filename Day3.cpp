#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
long long part1(std::vector<std::string> strings, int right, int down){
  long long cnt = 0;
  int num_strings = strings.size();
  int x = 0;
  for(int y = 0; y < num_strings;  y = y + down){
      if(strings[y][x % 31] == '#'){
        cnt++;
      }
      x = x + right;
  }
  return cnt;
}

// [[Rcpp::export]]
long long part2(std::vector<std::string> strings){
  return(
      part1(strings, 1, 1) *
      part1(strings, 3, 1) *
      part1(strings, 5, 1) *
      part1(strings, 7, 1) *
      part1(strings, 1, 2)
  );
}

/*** R
data <- scan('Day3.txt', what = character())
part1(data, 3, 1)
part2(data)
*/
