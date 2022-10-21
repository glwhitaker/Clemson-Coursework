// here are the required function signatures
// Gradescope will not work without them all included

bool isOdd(int n) {
  if(n % 2 == 0) return false;
  else return true;
}

int len3nplus1(int value) {
  int count = 0;
  while(value != 1){
    if(isOdd(value)){
      value = 3 * value + 1;
    }
    else{
      value = value / 2;
    }
    count++;
  }
  return count+1;
}

int sumSeq3nPlus1(int value) {
  int sum = value;
  while(value != 1){
    if(isOdd(value)){
      value = 3 * value + 1;
    }
    else{
      value = value / 2;
    }
    sum += value;
  }
  return sum;
}

int longestSequence(int max) {
  int longest = 0, longestIndex = 1, count;
  for(int i = 1; i <= max; i++){
    count = 1;
    int value = i;
    while(value != 1){
      if(isOdd(value)){
        value = 3 * value + 1;
      }
      else{
        value = value / 2;
      }
      count++;
    }
    if(count > longest){
      longest = count;
      longestIndex = i;
    }
  }
  return longestIndex;
}