#include<stdio.h>

int square(){
    int side,area,volume;

    printf("Enter the Side of the square:-\n");
    scanf("%d",&side);

    area=side*side;
    volume=area*side;

    printf("Area of the square is %d\nVolume of the cuboid is %d\n",area,volume);

    return 0;
}
int triangle(){
    int height,base,radius,area,volume;

    printf("Enter the height of the triangle:-\n");
    scanf("%d",&height);

    printf("Enter the base of the triangle:-\n");
    scanf("%d",&base);

    printf("Enter the radius of the triangle:-\n");
    scanf("%d",&radius);

    area=0.5*base*height;
    volume=3.14*radius*radius*height;

    printf("Area of the Triangle is %d\nVolume of the cone is %d\n",area,volume);

    return 0;
}
int circle(){
    int radius,area,volume;

    printf("Enter the radius of the circle-\n");
    scanf("%d",&radius);


    area=3.14*radius*radius;
    volume=(1.33)*3.14*radius*radius*radius;

    printf("Area of the circle is %d\nVolume of the sphere is %d\n",area,volume);

    return 0;
}

int main(){
    int n;
    printf("Which shape do you want to find the area and the volume?\n1)Square\n2)Triangle\n3)Circle\nEnter the option number...\n");
    scanf("%d",&n);
    switch(n){
        case 1:
            square();
            break;
        
        case 2:
            triangle();
            break;
        
        case 3:
            circle();
            break;
    }
}

