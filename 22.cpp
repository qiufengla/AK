#include<stdio.h>
#include<string.h>
 
int power(int* r, int n, int len_r) {
    int t1[1300] = { 0 };
    int len_t1 = len_r;
    for (int i = 0; i < len_r; i++)t1[i] = r[i];
    //t1����r�������߾��ȳ˷������һ������
    //t2������ų˷��е���ʱ����
    for (int i = 1; i < n; i++) {
        //ע�������1��ʼ����iҲ����<=n����<n
        //��Ϊn=1ʱ�����㣬n=2ʱ�Գ�1�Ρ���
        //n=nʱ�Գ�n-1��
        int t2[1300] = { 0 };
        for (int j = 0; j < len_t1; j++) {
            for (int k = 0; k < len_r; k++) {
                t2[j + k] += r[k] * t1[j];
                t2[j + k + 1] += t2[j + k] / 10;
                t2[j + k] %= 10;
            }//�߾��ȳ˷�����
        }
        int len_t2 = len_t1 + len_r;
        for (int j = 0; j < len_t2; j++)r[j] = t2[j];
        len_r = len_t2;
        //���³���r��ɾ��ǰ����
    }
    return len_r;
}
 
int main() {
    char s[1300];
    int r[1300] = { 0 };
    //һ��Ҫ��ʼ��Ϊ0
    //��������2����˵��ԭ��
    //ǰ����ȥ������С������λ�������
    int n;
    //�ݴδ���
    while (scanf("%s %d", s, &n) == 2) {
        int point = 0;
        for (int key = 0; key < strlen(s); key++) {
            if (s[key] == '.') {
                point = key;
                break;
            }
        }//�ҵ�С�����λ��point��
        //��key��Ҫ��ֹ�����s��2����2.0
        //��������һ����û������Ҳ���Բ���keyֱ����point
        int Ans_FracPart = (strlen(s) - 1 - point) * n;
        //����С����λ��
        int len_r = 0;
        for (int i = strlen(s) - 1; i >= 0; i--) {
            if (i == point && s[i] == '.')continue;
            r[len_r] = s[i] - '0';
            len_r++;
        }//�������С��sȥ��С������Ŵ�������r
        len_r = power(r, n, len_r);
        while (r[len_r - 1] == 0)len_r--;
        //ɾ��ǰ����
        int zero = 0;
        //zeroΪβ0����
        while (r[zero] == 0)zero++;
        int i;
        for (i = len_r - 1; i >= Ans_FracPart; i--)printf("%d", r[i]);
        //�����������
        if ((i == Ans_FracPart - 1 && Ans_FracPart - 1 >= zero) || i == len_r - 1)printf(".");
        //���С����(������С������ʱ���.�Լ�����������ʱҪ���.)
        for (int i = Ans_FracPart - 1; i >= zero; i--)printf("%d", r[i]);
        //���С������
        printf("\n");
        return 0; 
    }
    return 0;
}
