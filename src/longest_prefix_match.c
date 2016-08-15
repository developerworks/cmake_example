
#include "longest_prefix_match.h"

//求最长的公共前缀。
char *xtqz(char **arr,unsigned int length)
{
  unsigned int i=0; //指示应该匹配第i个字符串
  unsigned int j=0; // 指示应该匹配第j个字符
  char tmp1;        //第一个字符串的第j个字符
  char *result;     //返回的结果 也就是公共前缀
  unsigned int length2=strlen(arr[0]);//控制匹配字符的次数

  for(;j<length2;j++)
  {
    tmp1=*(arr[0]+j);//得到第一个字符的第j个字符，用来跟后面的字符串的第j个字符匹配
    for(i=1;i<length;i++)
    {
      if(j>=strlen(arr[i]))//也许第一个字符串长度不是最短的，如果有比它更短的就应该退出匹配
        break;

      if(*(arr[i]+j)!=tmp1) //如果当前字符串的第j字符与第一个字符串的第j个字符不匹配就退出
        break;

    }
    if(i!=length)//这就是匹配失败后的情况
    break;
  }
  if(j>0)
  {
    result=(char *)malloc(sizeof(j+1)); //匹配第j个失败，所以就分配j+1个内存
    strncpy(result,arr[0],j);//复制第一个字符串的前j个到结果并把末尾价格\0
    result[j]='\0';
  }
  return result;
}

int main()
{
  char *arr[] = {
    "Erlang/Elixir: Communicate with outside world - C Node",
    "Erlang/Elixir: Communicate with outside world - Port drivers",
    "Erlang/Elixir: Communicate with outside world - NIF"
  };
  printf("%s",xtqz(arr,3));
  return 0;
}
