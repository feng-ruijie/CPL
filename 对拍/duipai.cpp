#include<bits/stdc++.h>
using namespace std;
int main()
{
	int s = 0;
    while (1) //һֱѭ����ֱ���ҵ���һ��������
    {
        system("data.exe > in.txt");
        system("A.exe < in.txt > baoli.txt");
        system("B.exe < in.txt > std.txt");
        if (system("fc std.txt baoli.txt"))
		 //�� fc ���� 1 ʱ��˵����ʱ���ݲ�һ��
            break;    
        s++;
		cout << "�Ѿ�����" << s << endl;                      //��һ��������ѭ��
    }
    return 0;
}


