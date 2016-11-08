inline int read_int() {
   register char c=0;
   int a=0;
   while (c<33) c=getchar_unlocked();
   while (c>33) {
       a=a*10+c-'0';
       c=getchar_unlocked();
   }
   return a;
}
