#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char* DecToTex(long long num);
void AddLetter(char* tex, int num, int i);
void Perevorot(char* tex);
long long TexToDec(char *tex);
int SumPol(char *tex);

int main() {
    long long end = 0, cout = 0, check = 0;
    char *str1 = NULL, tex[] ="CCCCCC";
    end = TexToDec(tex);
    int sum = SumPol(tex), sum1 = 0;
    printf("Start counting the number of \"beautiful\" numbers\n");
    for (int j = 0; j <=sum; j++) {
        printf("Progress: %5.2f%%\n", j*100.0/72.0);
        for (int i = 0; i <= end; i++) {
            str1 = DecToTex(i);
            sum1 = SumPol(str1);
            if (sum1 == j) cout++;
            free(str1);
        }
        check+=cout*cout;
        cout = 0;
    }
    printf("\nNumber of \"beautiful\" numbers --> %lld\n", check*13);

    return 0;
}

char* DecToTex(long long num) {
    long long celoe = 100;
    int i = 0, ost = 100;
    char *tex = NULL;
    tex = calloc(100, 1);
    while (celoe >= 13) {
        celoe = num/13;
        ost = num%13;

        AddLetter(tex, ost, i);
        if (celoe < 13) {
            i++;
            AddLetter(tex, celoe, i);
        } else {
            num = celoe;
            i++;
        }
    }
    while (i < 5) {
        i++;
        tex[i] = '0';
    }
    tex[i+1] = '\0';
    Perevorot(tex);
    return tex;
}

long long TexToDec(char *tex) {
    long long num = 0;
    int step = 0;
    Perevorot(tex);
    int len = strlen(tex);
    for (int i = 0; i  < len; i++) {
        switch (tex[i]) {
            case 'A':
            num += 10 * pow(13, step);
            break;
            case 'B':
            num += 11 * pow(13, step);
            break;
            case 'C':
            num += 12 * pow(13, step);
            break;
            default:
            num += ((long long)(tex[i] - '0')) * pow(13, step);
            break;
        }
        step++;
    }
    Perevorot(tex);
    return num;
}

void AddLetter(char* tex, int num, int i) {
    switch (num) {
            case 10:
            tex[i] = 'A';
            break;
            case 11:
            tex[i] = 'B';
            break;
            case 12:
            tex[i] = 'C';
            break;
            default:
            tex[i] = num + '0';
            break;
        }
}

void Perevorot(char* tex) {
    int len = strlen(tex);
    char *new_tex = calloc(len + 1, 1);
    for (int i = 0; i < len; i++) {
        new_tex[i] = tex[len - i - 1];
    }
    for (int i = 0; i < len; i++) {
        tex[i] = new_tex[i];
    }
    free(new_tex);
}

int SumPol(char *tex) {
    int sum = 0;
    for (int i = 0; i <= 5; i++) {
        switch (tex[i]) {
            case 'A':
            sum += 10;
            break;
            case 'B':
            sum += 11;
            break;
            case 'C':
            sum += 12;
            break;
            default:
            sum += ((int)(tex[i] - '0'));
            break;
        }
    }
    return sum;
}
