int Solution::isPower(int A) {
    if(A==1)return 1;
    for(int i=2;i*i<=A;i++){
        int count=0;
        int num=A;
        if(num%i==0){
            while(num!=1){
                if(num%i==0)
                    count++;
                else break;
                num/=i;
            }
            if(num==1)return 1;
        }

    }
    return 0;
}
/*
  for i=2
  A=8 so logA= log8 = 3
  int c=logA/logi
  if(pow(i,c)==A)
    return 1;


*/
