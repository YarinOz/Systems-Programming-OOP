#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/**************************************************************************************************/
/***************************YOU MUST REMARK IT BEFORE SUBMISSION***********************************/
#define DEBUGON
/***************************YOU MUST REMARK IT BEFORE SUBMISSION***********************************/
/**************************************************************************************************/

/* Submitters
Name1: Yarin Oziel     ID: 319149878
Name2: Itamar Meir     ID: 208536888
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* structures */
typedef struct item {
    char* name;
    int  id;
    struct wlst* warehouses;    // item can be in multiple warehouses
} item;

typedef struct warehouse {
    char* name;
    int  code;
    struct itemlst* items;    // warehouse can contain multiple items
} warehouse;

typedef struct itemlst {
    item* data;
    struct itemlst* next;
} itemlst;

typedef struct wlst {
    warehouse* data;
    struct wlst* next;
} wlst;


/******************************************* your's prototypes *******************************************************************************/
void insert_item(itemlst** items, item* new_item);
void insert_warehouse(wlst** warehouses, warehouse* new_warehouse);
item* find_item(itemlst* items, int id);
warehouse* find_warehouse(wlst* warehouses, int code);
void assign_item_to_warehouse(item* item, warehouse* warehouse);
void unassign_item_from_warehouse(item* item, warehouse* warehouse);
void print_items(itemlst* items);
void free_items(itemlst* items);
void free_warehouses(wlst* warehouses);
int gen_100_10(itemlst** items, wlst** warehouses);
/******************************************* your's functions ********************************************************************************/

/*****************************************new objects and insert object functions******************************************************/
void insert_item(itemlst** items, item* new_item) {
    itemlst* new_node = (itemlst*)malloc(sizeof(itemlst));
    new_node->data = new_item;
    new_node->next = *items;
    *items = new_node;
}

void insert_warehouse(wlst** warehouses, warehouse* new_warehouse) {
    wlst* new_node = (wlst*)malloc(sizeof(wlst));
    new_node->data = new_warehouse;
    new_node->next = *warehouses;
    *warehouses = new_node;
}

/****************************************find Matchings and register item to Warehouse*************************************************/
item* find_item(itemlst* items, int id) {
    while (items) {
        if (items->data->id == id) {
            return items->data;
        }
        items = items->next;
    }
    return NULL;
}

warehouse* find_warehouse(wlst* warehouses, int code) {
    while (warehouses) {
        if (warehouses->data->code == code) {
            return warehouses->data;
        }
        warehouses = warehouses->next;
    }
    return NULL;
}

void assign_item_to_warehouse(item* item, warehouse* warehouse) {
    wlst* new_node = (wlst*)malloc(sizeof(wlst));
    new_node->data = warehouse;
    new_node->next = item->warehouses;
    item->warehouses = new_node;
}

/********************************************uregisters objects*************************************************************************/
void unassign_item_from_warehouse(item* item, warehouse* warehouse) {
    wlst** current = &(item->warehouses);
    while (*current) {              // iterate over the list of warehouses and remove the warehouse from the list
        if ((*current)->data == warehouse) {
            wlst* next = (*current)->next;
            free(*current);
            *current = next;
        } else {
            current = &((*current)->next);
        }
    }
}

/***********************************************printout functions***********************************************************************/
void print_items(itemlst* items) {
    while (items) {
        printf("Item name: %s, ID: %d\n", items->data->name, items->data->id);
        items = items->next;
    }
}

/***************************************************free**********************************************************************************/
void free_items(itemlst* items) {
    while (items) {
        itemlst* next = items->next;
        free(items->data->name);
        free(items->data);
        free(items);
        items = next;
    }
}

void free_warehouses(wlst* warehouses) {
    while (warehouses) {
        wlst* next = warehouses->next;
        free(warehouses->data->name);
        free(warehouses->data);
        free(warehouses);
        warehouses = next;
    }
}

/*******************************************Generate And Assign Items And Warehouses******************************************************/
// int gen_100_10(itemlst** items, wlst** warehouses) {
//     srand(1948);

//     // Create 10 warehouses
//     for (int i = 0; i < 10; i++) {
//         char location[10];
//         sprintf(location, "warehouse%d", i);
//         warehouse* new_warehouse = (warehouse*)malloc(sizeof(warehouse));
//         new_warehouse->name = (char*)malloc(strlen(location) + 1);
//         strcpy(new_warehouse->name, location);
//         new_warehouse->code = i;
//         new_warehouse->items = 0;
//         insert_warehouse(warehouses, new_warehouse);
//     }

//     // Create 100 items and assign them to warehouses
//     for (int i = 0; i < 100; i++) {
//         char name[10];
//         sprintf(name, "item%d", i);
//         item* new_item = (item*)malloc(sizeof(item));
//         new_item->name = (char*)malloc(strlen(name) + 1);
//         strcpy(new_item->name, name);
//         new_item->id = i;
//         new_item->warehouses = 0;
//         insert_item(items, new_item);

//         // Assign the item to a warehouse
//         warehouse* warehouse_to_assign = find_warehouse(*warehouses, i % 10);
//         assign_item_to_warehouse(new_item, warehouse_to_assign);
//     }

//     return 0;
// }
/*******************************************Main Function**********************************************************************************/
/*DO NOT TOUCH THIS FUNCTION */
void getstring(char* buf, int length) {
    int len;
    //buf = fgets(buf, length, stdin);
	scanf("%s", buf);
    len = (int)strlen(buf);
    if (buf[len - 1] == '\n')
        buf[len - 1] = '\0';
}


/*DO NOT TOUCH THIS FUNCTION */

void print_error_message(int errid) {
	#ifdef DEBUGON
	fprintf(stderr, "BGU ERROR %d\n", errid);
	#else
	fprintf(stderr, "BGU ERROR\n");	
	#endif
	exit(-1);
}

/*DO NOT TOUCH THIS MAIN TEMPLATE - ONLY ADD YOUR FUNCTIONS CALLS */
int main() {
    itemlst* items = 0;
    wlst* warehouses = 0;
    char  c;
    char  buf[100];
    int   id, num;
	


    do {
        printf("Choose:\n"
            "    i - new item\n"
            "    w - new warehouse\n"
            "    a - assign an item to a warehouse\n"
            "    u - unassign an item from a warehouse(not delete!)\n"
            "    p - print status\n"
			"    g - generating and assigning 100 items to 10 warehouses\n"
            "    q - quit\n");

        while ((c = (char)getchar()) == '\n');
        getchar();

        switch (c) {
        case 'i':
            printf("Adding new item.\n");

            printf("item name: ");
            getstring(buf, 100);
			

            printf("item ID: ");
            scanf("%d", &id);
			
			printf("\n Add new item: name %s item id: %d",buf, id);
            
			//your function
            if (find_item(items, id)) {
                #ifdef DEBUGON
                printf("Item with ID %d already exists\n", id);
                #endif
                break;
            }
            item* new_item = (item*)malloc(sizeof(item));
            new_item->name = (char*)malloc(strlen(buf) + 1);
            new_item->id = id;
            insert_item(&items, new_item);

            break;

        case 'w':
            printf("Adding new warehouse.\n");

            printf("\n warehouse name: ");
            getstring(buf, 100);

            printf("\n warehouse code: ");
            scanf("%d", &num);
			
			printf("\n Add new warehouse: name %s warehouse code: %d",buf, num);
            
			//your function
            if (find_warehouse(warehouses, num)) {
                #ifdef DEBUGON
                printf("Warehouse with code %d already exists\n", num);
                #endif
                break;
            }
            warehouse* new_warehouse = (warehouse*)malloc(sizeof(warehouse));
            new_warehouse->name = (char*)malloc(strlen(buf) + 1);
            new_warehouse->code = num;
            insert_warehouse(&warehouses, new_warehouse);

            break;

        case 'a':
            printf("Assign an item to a warehouse.\n");

            printf("item ID: ");
            scanf("%d", &id);

            printf("warehouse code: ");
            scanf("%d", &num);

            //your function
            item* item_to_assign = find_item(items, id);
            warehouse* warehouse_to_assign = find_warehouse(warehouses, num);
            if (!item_to_assign || !warehouse_to_assign) {
                #ifdef DEBUGON
                printf("Item or warehouse not found\n");
                #endif
                break;
            }
            assign_item_to_warehouse(item_to_assign, warehouse_to_assign);
            break;

        case 'u':
            printf("Remove an item from a warehouse.\n");

            printf("item ID: ");
            scanf("%d", &id);

            printf("warehouse code: ");
            scanf("%d", &num);

           //your function

            break;

        case 'p':
            printf("Printing status.\n");

            print_items(items);
            //your function

            break;
			
		case 'g':  // generating and assigning items and warehouses
			printf("Generating and assigning items to warehouses\n");
		
			//your function
			
			break;

        case 'q':
            printf("Quitting...\n");
            break;
        }

        if (c != 'q')
            printf("\n");
    } while (c != 'q');

    //your free functions
	exit(0);
    
}




