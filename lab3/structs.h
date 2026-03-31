
typedef struct{
    char name[50];
    char position[50];
    int year;
    double salary;
} Worker;

typedef enum{IT,ECONOMICS,LAW,MANAGEMENT} Faculty;

typedef struct{
    char name[50];
    int course;
    double avg;
    Faculty faculty;
} Student;

typedef enum{CASH,CARD,TRANSFER} PaymentType;

typedef union{
    char card[20];
    char iban[30];
} PaymentData;

typedef struct{
    int id;
    PaymentType type;
    PaymentData data;
} Payment;
