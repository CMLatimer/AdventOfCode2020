#include <Rcpp.h>
#include <fstream>
#include <regex>
#include <string>
using namespace Rcpp;

// [[Rcpp::export]]
int part1(std::string file) {
  std::ifstream infile(file);
  std::string line;
  std::string big_line;
  //std::string space (" ");
  std::regex re("(?=.*byr:)(?=.*iyr:)(?=.*eyr:)(?=.*hgt:)(?=.*pid:)(?=.*ecl:)(?=.*hcl:)");
  int cnt = 0;
  while(getline(infile, line)){
    big_line = line;
    while(line.length() > 0){
      getline(infile, line);
      big_line.append(" ");
      big_line.append(line);
    }
    big_line.append(" ");
    if(std::regex_search(big_line, re))
      //Rcout << big_line << '\n';
    cnt++;
  }
  return cnt;
}

// [[Rcpp::export]]
int part2(std::string file) {
  std::ifstream infile(file);
  std::string line;
  std::string big_line;
  std::regex re("((?=.*(byr:(19[2-9][0-9]|200[0-2])))(?=.*(iyr:(201[0-9]|2020)))(?=.*(eyr:(202[0-9]|2030)))(?=.*(hgt:(((1[5-8][0-9]|19[0-3])cm)|(59|6[0-9]|7[0-6])in)))(?=.*(pid:\\d{9} ))(?=.*(ecl:(amb|blu|brn|gry|grn|hzl|oth) ))(?=.*(hcl:#([a-z]|[0-9]){6} )))");
  int cnt = 0;
  while(getline(infile, line)){
    big_line = line;
    while(line.length() > 0){
      getline(infile, line);
      big_line.append(" ");
      big_line.append(line);
    }
    big_line.append(" ");
    if(std::regex_search(big_line, re))
      //Rcout << big_line << '\n';
      cnt++;
  }
  return cnt;
}



/*** R
part1("Day4.txt")
part2("Day4.txt")
*/
