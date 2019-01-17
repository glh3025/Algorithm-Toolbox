#include <iostream>
#include <string>

using std::string;

int edit_distance(const string &str1, const string &str2) {
  //write your code here
  int n = str1.length();
  int m = str2.length();
  int D[n+1][m+1] = {0};
  for (int i = 0;i<=n; i++) D[i][0] = i;
  for (int j = 0;j<=m; j++) D[0][j] = j;
  int insertion,deletion,match,mis_match,a,b;
  for (int j = 1;j<=m; j++){
    for (int i = 1;i<=n;i++){
        insertion = D[i][j-1]+1;
        deletion = D[i-1][j]+1;
        match = D[i-1][j-1];
        mis_match = D[i-1][j-1]+1;
        if (str1[i-1]==str2[j-1]){
            a = std::min(insertion,deletion);
            b = std::min(deletion,match);
            D[i][j]=std::min(a,b);
//            D[i][j]=insertion;
//            if (deletion<=insertion) D[i][j]= deletion;
//            if (match<=deletion && deletion<=insertion) D[i][j]= match;
        }
        else{
            a = std::min(insertion,deletion);
            b = std::min(deletion,mis_match);
            D[i][j]=std::min(a,b);
//            D[i][j]=insertion;
//            if (deletion<=insertion) D[i][j]= deletion;
//            if (mis_match<=deletion && deletion<=insertion) D[i][j]= mis_match;
        }
    }
  }



  return D[n][m];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
