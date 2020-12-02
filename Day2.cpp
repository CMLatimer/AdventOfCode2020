#include <Rcpp.h>
#include <algorithm>
using namespace Rcpp;

// Part 1
// [[Rcpp::export]]
int part1(std::vector<std::string> strings){
  int num_strings = strings.size();
  int result = 0;
  
  for(int i = 0; i < num_strings; i++){
    int min = std::stoi(strings[i].substr(0,strings[i].find('-')));
    int max = std::stoi(strings[i].substr(strings[i].find('-')+1, strings[i].find(' ') - strings[i].find('-') - 1));
    char letter = strings[i].substr(strings[i].find(' ')+1,strings[i].find(':') - strings[i].find(' ') - 1)[0];
    std::string password = strings[i].substr(strings[i].find(':')+2, std::string::npos);
    int cnt = std::count(password.begin(), password.end(), letter);
    if((min <= cnt) & (cnt <= max)){
      result++;
    }
  }
  return result;
}

/*** R
#data <- c(
#   '1-3 a: abcde'
#  ,'1-3 b: cdefg'
#  ,'2-9 c: ccccccccc'
#)
data <- scan('Day2.txt', sep = '\n', what = character())
part1(data)
*/