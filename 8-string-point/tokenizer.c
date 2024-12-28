#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char res[][10]={"const","int","float","double","long", "static", "void", "char", "extern", "return", "break", "enum", "struct", "typedef", "union", "goto"};
char s[4200];
int q = 0,tot = 0;
char map[4200][4200];
int output[20007],len[4200];
void process(int n){
    int i = 0; 
    while(i < n){
    	//	printf("%c\n",s[i]);
            if(s[i] == ' '){
                i++; 
                continue;
            }
            int is_res = 0;
            for(int j=0;j<16;j++){
                int p = 0;
                for(int k=0;k<strlen(res[j]);k++){
                    if(res[j][k] != s[i+k]){
                        p = 1;
                        break;
                    }
                }
                if(i+strlen(res[j]) >= n || s[i+strlen(res[j])] == ' '){
                    if(p == 0){
                    is_res = 1;
                    output[tot++] = 1;
                    i += strlen(res[j]);
                    break;
                }
                }
            }
            if(is_res == 1){
                continue;
            }
           /*if(s[i] == '-' && s[i+1] <= '9' && s[i+1] >= '0'){ //负数不应直接连整数
                printf("Compile Error\n");
                q=1;
                return; 
            }*/
            if(((s[i] == '=' && s[i+1] == '=') || (s[i] == '>' && s[i+1] == '=') || (s[i] == '<' && s[i+1] == '=') || (s[i] == '!' && s[i+1] == '='))&&(i+2>=n||s[i+2]==' ')){
                output[tot++] = 4;
                i += 2;
                continue;
            }
            if((s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '>' || s[i] == '<' || s[i] == '=')&&(i+1>=n || s[i+1] == ' ')){
                output[tot++] = 4;
                i++;
                continue;
            }
            int count_dot = 0,is_num = 0;
            if(s[i] == '.' || (s[i] >= '0' && s[i] <= '9')){
                while(s[i] != ' ' && i < n){
                    if(s[i] == '.'){
                        count_dot++;
                    }
                    else if(s[i] >= '0' && s[i] <= '9'){
                        is_num = 1;
                    }
                    else{ //数字后面接字符
                        printf("Compile Error\n");
                        q=1;
                        return;
                    }
                    i++;
                }
                if(count_dot > 1 || is_num == 0){
                    printf("Compile Error\n");
                    q=1;
                    return;
                }
                if(count_dot == 0 && is_num == 1){
                    output[tot++] = 2;
                }
                else if(count_dot == 1 && is_num == 1){
                    output[tot++] = 3;
                }
                continue;
            }
            int is_id = 0;
            while(s[i] != ' ' && i < n){
                if((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] == '_') || (s[i] >= 'A' && s[i] <= 'Z')){
                	i++;
					continue;	
				} 
                is_id = 1;
                break;
            }
            if(is_id == 0){
                output[tot++] = 5;
            }
            else{
                printf("Compile Error\n");
                q=1;
                return;
            }
        }
    tot ++;
}
int main(){
	char s1[4200];
    int t=0;
    memset(output,0,sizeof(output));
    while(fgets(s1,4200,stdin)!=NULL){
    	t++;
    	for(int i=0;i<strlen(s1);i++){
    		map[t][i] = s1[i]; 
		}
	}
	int nw = 0;
	for(int i=1;i<=t;i++){
		for(int j=0;j<strlen(map[i]);j++){
		    if(map[i][j] == '\n'){ 
		        if(i==t) continue;
		        else{
		            s[nw++] = ' ';
		            continue;
		        }
		    } 
			if(map[i][j] != ';'){
			    if(nw == 0 && map[i][j] == ' ') continue;
				s[nw++] = map[i][j];
			}
			else{
				process(nw);
				if(q == 1) return 0;
				nw = 0;
				memset(s,' ',sizeof(s));
			}
		}
	}
	if(nw != 0 ){
		printf("Compile Error");
		return 0;
	}
	
	for(int i=0;i<tot;i++){
	    if(output[i] == 0) printf("\n");
        if(output[i] == 1) printf("reserved ");
        if(output[i] == 2) printf("integer ");
        if(output[i] == 3) printf("float ");
        if(output[i] == 4) printf("operator ");
        if(output[i] == 5) printf("variable ");
    }
	
}