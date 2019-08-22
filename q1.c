#include<stdio.h> 
#include<string.h> 
  
char findClass(char str[]) 
{ 
    char arr[4]; 
    int i = 0; 
    while (str[i] != '.') 
    { 
        arr[i] = str[i]; 
        i++; 
    } 
    i--; 
  
    int ip = 0, j = 1; 
    while (i >= 0) 
    { 
        ip = ip + (str[i] - '0') * j; 
        j = j * 10; 
        i--; 
    } 
  
    if (ip >=1 && ip <= 126) 
        return 'A'; 
  
    else if (ip >= 128 && ip <= 191) 
        return 'B'; 
  
    else if (ip >= 192 && ip <= 223) 
        return 'C'; 
  
    else if (ip >= 224 && ip <= 239) 
        return 'D'; 
  
    else
        return 'E'; 
} 
  
void separate(char str[], char ipClass) 
{ 
    char network[12], host[12]; 
    for (int k = 0; k < 12; k++) 
        network[k] = host[k] = '\0'; 
  
    if (ipClass == 'A') 
    { 
        int i = 0, j = 0; 
        while (str[j] != '.') 
            network[i++] = str[j++]; 
        i = 0; 
        j++; 
        while (str[j] != '\0') 
            host[i++] = str[j++]; 
        printf("Network ID is %s\n", network); 
        printf("Host ID is %s\n", host); 
    } 
   
    else if (ipClass == 'B') 
    { 
        int i = 0, j = 0, dotCount = 0; 
  
        while (dotCount < 2) 
        { 
            network[i++] = str[j++]; 
            if (str[j] == '.') 
                dotCount++; 
        } 
        i = 0; 
        j++; 
  
        while (str[j] != '\0') 
            host[i++] = str[j++]; 
  
        printf("Network ID is %s\n", network); 
        printf("Host ID is %s\n", host); 
    } 
  
    else if (ipClass == 'C') 
    { 
        int i = 0, j = 0, dotCount = 0; 
  
        while (dotCount < 3) 
        { 
            network[i++] = str[j++]; 
            if (str[j] == '.') 
                dotCount++; 
        } 
  
        i = 0; 
        j++; 
  
        while (str[j] != '\0') 
            host[i++] = str[j++]; 
  
        printf("Network ID is %s\n", network); 
        printf("Host ID is %s\n", host); 
    } 
  
    else
        printf("In this Class, IP address is not"
           " divided into Network and Host ID\n"); 
} 
  
int main() 
{ 
    // an example of class C
    char str[] = "192.226.12.11"; 
 
    printf("\n");
    printf("Input IP address is: %s\n", str);
    char ipClass = findClass(str); 
    printf("Given IP address belongs to Class %c\n", ipClass);
    separate(str, ipClass); 
    printf("\n");

    // an example of Class A
    char str1[] = "1.4.5.5"; 
 
    printf("Input IP address is: %s\n", str1);
    char ipClass1 = findClass(str1); 
    printf("Given IP address belongs to Class %c\n",ipClass1); 
    separate(str1, ipClass1); 
    printf("\n");
    return 0; 
} 

