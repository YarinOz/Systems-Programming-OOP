#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/**************************************************************************************************/
/***************************YOU MUST REMARK IT BEFORE SUBMISSION***********************************/
//#define DEBUGON
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
void unassign_warehouse_from_item(warehouse* warehouse, item* item);
void print_items(itemlst* items);
void print_warehouse(wlst* warehouses);
void free_items(itemlst* items);
void free_warehouses(wlst* warehouses);
void gen_100_10(itemlst** items, wlst** warehouses);
/******************************************* your's functions ********************************************************************************/

/*****************************************new objects and insert object functions******************************************************/
void insert_item(itemlst** items, item* new_item) {
    itemlst* new_node = (itemlst*)malloc(sizeof(itemlst));
    new_node->data = new_item;
    new_node->next = NULL; // Set the next pointer of the new node to NULL

    if (*items == NULL) {
        *items = new_node; // If the list is empty, make the new node the head of the list
    } else {
        itemlst* current = *items;
        if (current->data->id > new_item->id) { // If the new node should be the head of the list
            new_node->next = current;
            *items = new_node;
            return;
        }
        while (current->next != NULL && (current->next->data->id < new_item->id)) {
            current = current->next; // Traverse to the last node of the list
        }
        itemlst* temp = current->next; // Save the next pointer of the current node
        current->next = new_node; 
        new_node->next = temp;
    }
}

void insert_warehouse(wlst** warehouses, warehouse* new_warehouse) {
    wlst* new_node = (wlst*)malloc(sizeof(wlst));
    new_node->data = new_warehouse;
    new_node->next = NULL; // Set the next pointer of the new node to NULL

    if (*warehouses == NULL) {
        *warehouses = new_node; // If the list is empty, make the new node the head of the list
    } else {
        wlst* current = *warehouses;
        if (current->data->code > new_warehouse->code) { // If the new node should be the head of the list
            new_node->next = current;
            *warehouses = new_node;
            return;
        }
        while (current->next != NULL && (current->next->data->code < new_warehouse->code)) {
            current = current->next; // Traverse to the last node of the list
        }
        wlst* temp = current->next; // Save the next pointer of the current node
        current->next = new_node;
        new_node->next = temp;
    }
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
    // Assign warehouse to item
    wlst* new_node = (wlst*)malloc(sizeof(wlst));
    new_node->data = warehouse;
    new_node->next = NULL;
    if (item->warehouses == NULL) {
        item->warehouses = new_node;
    } else {
        wlst* current = item->warehouses;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    // Assign item to warehouse
    itemlst* new_item_node = (itemlst*)malloc(sizeof(itemlst));
    new_item_node->data = item;
    new_item_node->next = NULL;
    if (warehouse->items == NULL) {
        warehouse->items = new_item_node;
    } else {
        itemlst* current_item = warehouse->items;
        while (current_item->next != NULL) {
            current_item = current_item->next;
        }
        current_item->next = new_item_node;
    }
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

void unassign_warehouse_from_item(warehouse* warehouse, item* item) {
    itemlst** current = &(warehouse->items);
    while (*current) {              // iterate over the list of items and remove the item from the list
        if ((*current)->data == item) {
            itemlst* next = (*current)->next;
            free(*current);
            *current = next;
        } else {
            current = &((*current)->next);
        }
    }
}

/***********************************************printout functions***********************************************************************/
void print_items(itemlst* items) {
    printf("item LIST:\n");
    while (items) {
        printf("%d:%s", items->data->id, items->data->name);
        wlst* wares = items->data->warehouses;
        if (wares) {
            printf("\nItem Warehouses: ");
            // printf("None");
        }
        while (wares) {
            printf("%d-%s", wares->data->code, wares->data->name);
            if (wares->next != NULL) {
                printf(", ");
            }
            wares = wares->next;
        }
        printf("\n");
        items = items->next;
    }
}

void print_warehouse(wlst* warehouses) {
    printf("warehouse LIST:\n");
    while (warehouses) {
        printf("Warehouse code %d, Warehouse name: %s", warehouses->data->code, warehouses->data->name);
        itemlst* items = warehouses->data->items;
        if (items) {
            printf("\nitems: ");
            // printf("None");
        }
        while (items) {
            printf("ID %d Name %s | ", items->data->id, items->data->name);
            items = items->next;
        }
        printf("\n");
        warehouses = warehouses->next;
    }
}

/***************************************************free**********************************************************************************/
void free_items(itemlst* items) {
    while (items) {
        itemlst* next = items->next;
        while(items->data->warehouses) {  // free the list of warehouses from item
            wlst* next_warehouse = items->data->warehouses->next;
            unassign_warehouse_from_item(items->data->warehouses->data, items->data);
            items->data->warehouses = next_warehouse;
        }
        free(items->data->name);
        free(items->data);
        free(items);
        items = next;
    }
}

void free_warehouses(wlst* warehouses) {
    while (warehouses) {
        wlst* next = warehouses->next;
        while(warehouses->data->items) {  // free the list of items from warehouse
            itemlst* next_item = warehouses->data->items->next;
            unassign_item_from_warehouse(warehouses->data->items->data, warehouses->data);
            warehouses->data->items = next_item;
        }
        free(warehouses->data->name);
        free(warehouses->data);
        free(warehouses);
        warehouses = next;
    }
}

/*******************************************Generate And Assign Items And Warehouses******************************************************/
void gen_100_10(itemlst** items, wlst** warehouses) {
    srand(1948);

    // Create 10 warehouses
    for (int i = 0; i < 10; i++) {
        char location[20];
        sprintf(location, "Warehouse%d", i);
        if (find_warehouse(*warehouses, i)) {
            #ifdef DEBUGON
            printf("Warehouse with code %d already exists\n", i);
            #endif
            continue;
        }
        warehouse* new_warehouse = (warehouse*)malloc(sizeof(warehouse));
        new_warehouse->name = (char*)malloc(strlen(location) + 1);
        strcpy(new_warehouse->name, location);
        new_warehouse->code = i;
        new_warehouse->items = 0;
        insert_warehouse(warehouses, new_warehouse);
    }

    // Create 100 items and assign them to warehouses
    for (int i = 0; i < 100; i++) {
        char name[10];
        sprintf(name, "Item%d", i);
        if (find_item(*items, i)) {
            #ifdef DEBUGON
            printf("Item with ID %d already exists\n", i);
            #endif
            continue;
        }
        item* new_item = (item*)malloc(sizeof(item));
        new_item->name = (char*)malloc(strlen(name) + 1);
        strcpy(new_item->name, name);
        new_item->id = i;
        new_item->warehouses = 0;
        insert_item(items, new_item);
    }
    // Assign the item to a warehouse
    for (int i = 0; i < 100; i++) {
        int randomCode = rand() % 10;
        warehouse* warehouse_to_assign = find_warehouse(*warehouses, randomCode);
        assign_item_to_warehouse(find_item(*items, i), warehouse_to_assign);}
}
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
            strcpy(new_item->name, buf);
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
            strcpy(new_warehouse->name, buf);
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
            item* item_to_unassign = find_item(items, id);
            warehouse* warehouse_to_unassign = find_warehouse(warehouses, num);
            if (!item_to_unassign || !warehouse_to_unassign) {
                #ifdef DEBUGON
                printf("Item or warehouse not found\n");
                #endif
                break;
            }
            unassign_item_from_warehouse(item_to_unassign, warehouse_to_unassign);
            break;

        case 'p':
            printf("Printing status.\n");
 
            print_items(items);
            print_warehouse(warehouses);

            break;
			
		case 'g':  // generating and assigning items and warehouses
			printf("Generating and assigning items to warehouses\n");
		
			//your function
            gen_100_10(&items, &warehouses);
			break;

        case 'q':
            printf("Quitting...\n");
            break;
        }

        if (c != 'q')
            printf("\n");
    } while (c != 'q');

    //your free functions
    
    free_items(items);
    free_warehouses(warehouses);
    
	exit(0);
    
}




