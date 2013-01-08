#ifndef MYLIB_H
#define MYLIB_H

int	lenStr(char* s) {
	int	ret;
	for (ret=0;*(s+ret);ret++);
	return ret;
}

char*	cpyStr(char*s) {
	char	*ret,*tmp;
	ret=(char*)malloc(sizeof(char)*(lenStr(s)+1));
	for(tmp=ret;*tmp=*s;s++,tmp++);
	return ret;
}

#endif /* MYLIB_H */
