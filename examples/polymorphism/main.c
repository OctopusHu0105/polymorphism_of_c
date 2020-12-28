/* Blink Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>

static const char *TAG = "SHAPE";

#define NULL_CHECK(TAG, a, action, msg) if (!(a)) {                                \
        ESP_LOGE(TAG,"%s:%d (%s): %s", __FILE__, __LINE__, __FUNCTION__, msg);  \
        action;                                                                      \
        }

struct esp_shape {
    int32_t x;
    int32_t y; 
};

typedef struct esp_shape* esp_shape_t;

esp_shape_t shape_init(int32_t x, int32_t y)
{
    esp_shape_t shape = malloc(sizeof(struct  esp_shape));
    NULL_CHECK(TAG, shape, return NULL, "get null");
    shape->x = x;
    shape->y = y;
    return shape;
}

void shape_add(esp_shape_t shape, int32_t dx, int32_t dy)
{
    shape->x += dx;
    shape->y += dy;
}

int32_t shape_get_x(esp_shape_t shape)
{
    return shape->x;
}

int32_t shape_get_y(esp_shape_t shape)
{
    return shape->y;
}

struct esp_rectangle {
    esp_shape_t shape;
    uint32_t    width;
    uint32_t    height;
};
typedef struct esp_rectangle* esp_rectangle_t;

// esp_rectangle_t esp_rectangle_init(esp_shape_t shape, uint32_t width, uint32_t height)
// {
//     NULL_CHECK(TAG, shape, return NULL, "get null");
//     esp_rectangle_t rectangle = malloc(struct esp_rectangle);
//     rectangle->shape  = shape;
//     rectangle->width  = width;
//     rectangle->height = height;
//     return rectangle;
// }

// struct shape_func {
//     uint32_t (*area)(esp_shape_t shape);
//     void (*draw)(esp_shape_t shape);
// };

// typedef struct shape_func* shape_func_t; 

// struct esp_new_shape {
//     shape_func_t func;
//     uint32_t     x;
//     uint32_t     y;
// };

// typedef struct esp_new_shape* esp_new_shape_t;

// static uint32_t shape_area(esp_new_shape_t new_shape)
// {
//     return (new_shape->func->area)(new_shape);
// }

// static uint32_t shape_draw(esp_new_shape_t new_shape)
// {
//     return (new_shape->func->draw)(new_shape);
// }


// static uint32_t _shape_area(esp_new_shape_t new_shape);
// static uint32_t _shape_draw(esp_new_shape_t new_shape);

// //gou zao 
// esp_new_shape_t new_shape_init(int32_t x, int32_t y)
// {
//     esp_new_shape_t new_shape = (esp_new_shape_t)malloc(sizeof(struct esp_new_shape));
    
//     static shape_func_t func = {
//         _shape_area,
//         _shape_draw
//     };
    
//     new_shape->func = func;
//     new_shape->x    = x;
//     new_shape->y    = y;

//     return new_shape;
// }

// void new_shape_add(esp_new_shape_t new_shape, int32_t dx, int32_t dy)
// {
//     new_shape->x += dx;
//     new_shape->y += dy;
// }

// int32_t new_shape_get_x(esp_new_shape_t new_shape)
// {
//     return new_shape->x;
// }

// int32_t new_shape_get_y(esp_new_shape_t new_shape)
// {
//     return new_shape->y;
// }

// static uint32_t _shape_area(esp_new_shape_t new_shape)
// {
//     assert(0);
//     return 0;
// }

// static uint32_t _shape_draw(esp_new_shape_t new_shape)
// {
//     assert(0);
// }

// esp_new_shape_t largest_new_shape(esp_new_shape_t new_shape[], uint32_t num)
// {
//     esp_new_shape_t new_s = (esp_new_shape_t)0;
//     uint32_t max = 0;
//     for (int i = 0; i < num; i++) {
//         uint32_t area = shape_area(new_shape[i]);
//         if (area > max) {
//             max = area;
//             new_s = new_shape[i];
//         }
//     }
//     return new_s;
// }

// void draw_all_new_shape(esp_new_shape_t new_shape[], uint32_t num)
// {
//     for (int i = 0; i < num; i++) {
//         shape_draw(new_shape[i]);
//     }
// }

// rectangle xu
// static uint32_t _rectangle_area(esp_new_shape_t new_shape);
// static void _rectangle_draw(esp_new_shape_t new_shape);

// esp_rectangle_t esp_rectangle_init(int16_t x, int16_t y, int16_t weight, int16_t height)
// {
    
//     return NULL;
// }


int min(int x, int y)
{
    return x < y ? x : y;
}

void merge_sort(int *arr, int len)
{
    int *a = arr;
    int *b = (int *)malloc(len * sizeof(int));
    int seg, start;

    for (seg = 1; seg < len; seg += seg) {
        printf("---> seg : %d \n", seg);
        for (start = 0; start < len; start += seg * 2) {
            
            int low = start;
            int mid = min(start + seg, len);
            int hig = min(start + seg *2, len);
            int k = low;
            int start1 = low;
            int end1 = mid;
            int start2 = mid;
            int end2 = hig;
            printf("---> 1 :low %d , mid %d hig %d  k %d start1 %d end1 %d start2 %d end2 %d \n", low , mid, hig,  k, start1,end1, start2, end2);
            
            while (start1 < end1 && start2 < end2) {
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            }
            // printf("---> 2 : k %d start1 %d end1 %d start2 %d end2 %d \n", k, start1,end1, start2, end2);
            while (start1 < end1) {
                b[k++] = a[start1++];
            }
            // printf("---> 3 :k %d start1 %d end1 %d start2 %d end2 %d \n", k, start1,end1, start2, end2);
            
            while (start2 < end2) {
                b[k++] = a[start2++];
            }
            printf("---> :k %d \n", k);
        }
        
        int *temp = a;
        printf(" (1) %p   %p   %p \n", a, b ,temp);
        a = b;
         printf(" (2) %p   %p   %p \n", a, b ,temp);
        b = temp;
         printf(" (3) %p   %p   %p \n", a, b ,temp);

        // for (int i = 0; i < 11; i++) {
        //     a[i] = b[i];
        // }

         printf("---> \n\n\n\n"); 
    }
    // if (a != arr) {
    //     for (int i = 0; i < len; i++) {
    //         b[i] = a[i];
    //     }
    //     b = a;
    // }
}


void app_main()
{
    // esp_shape_t shape = shape_init(2, 3);

    int a[11] = {42, 5, 98, 32, 23, 67, 58, 89, 34, 33, 44};

    merge_sort(a, 11);
     printf(" after:");
   for (int i = 0; i < 11; i++) {
       printf(" %d ", a[i]);
   }
   printf("\n");
	while (1) {
        vTaskDelay(1000 / portTICK_PERIOD_MS);  
    }
  
}
