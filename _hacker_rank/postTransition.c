#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_LENGTH 6

struct package {
    char *id;
    int weight;
};
typedef struct package package;

struct post_office {
    int min_weight;
    int max_weight;
    package *packages;
    int packages_count;
};
typedef struct post_office post_office;

struct town {
    char *name;
    post_office *offices;
    int offices_count;
};
typedef struct town town;

void print_all_packages(town t) {
    printf("%s:\n", t.name);
    for (int i = 0; i < t.offices_count; i++) {
        printf("\t%d:\n", i);
        for (int j = 0; j < t.offices[i].packages_count; j++) {
            printf("\t\t%s\n", t.offices[i].packages[j].id);
        }
    }
}

void send_all_acceptable_packages(town *source, int source_office_index, town *target, int target_office_index) {
    /* int source_packages_count = source->offices[source_office_index].packages_count;
    int target_packages_count = target->offices[target_office_index].packages_count;
    int target_min_weight = target->offices[target_office_index].min_weight;
    int target_max_weight = target->offices[target_office_index].max_weight;

    for (int i = 0; i < source_packages_count; i++) {
        if (source->offices[source_office_index].packages[i].weight >= target_min_weight && source->offices[source_office_index].packages[i].weight <= target_max_weight) {
            target->offices[target_office_index].packages_count++;
            target->offices[target_office_index].packages = realloc(target->offices[target_office_index].packages, sizeof(package) * target->offices[target_office_index].packages_count);
            target->offices[target_office_index].packages[target_packages_count] = source->offices[source_office_index].packages[i];
            source->offices[source_office_index].packages_count--;
            source->offices[source_office_index].packages[i] = source->offices[source_office_index].packages[source_packages_count - 1];
            source->offices[source_office_index].packages = realloc(source->offices[source_office_index].packages, sizeof(package) * source->offices[source_office_index].packages_count);

            i--;
            target_packages_count++;
            source_packages_count--;
        }
    } */
    post_office *src = source->offices + source_office_index;
    post_office *tar = target->offices + target_office_index;
    package temple[src->packages_count];
    int temple_size = 0;
    for (int i = 0; i < src->packages_count;) {
        if (src->packages[i].weight >= tar->min_weight &&
            src->packages[i].weight <= tar->max_weight) {
            temple[temple_size++] = src->packages[i];
            for (int j = i; j < src->packages_count - 1; j++) {
                src->packages[j] = src->packages[j + 1];
            }
            src->packages_count--;
        } else
            i++;
    }
    tar->packages = realloc(tar->packages, (tar->packages_count + temple_size) * sizeof(package));
    for (int i = 0; i < temple_size; i++) {
        tar->packages[tar->packages_count++] = temple[i];
    }
}

town town_with_most_packages(town *towns, int towns_count) {
    int towns_most_packages = 0, town_index = 0, max_packages = 0;

    for (int i = 0; i < towns_count; i++) {
        for (int j = 0; j < towns[i].offices_count; j++) {
            towns_most_packages += towns[i].offices[j].packages_count;
        }
        if (towns_most_packages > max_packages) {
            max_packages = towns_most_packages;
            town_index = i;
        }
        towns_most_packages = 0;
    }

    return towns[town_index];
}

town *find_town(town *towns, int towns_count, char *name) {
    for (int i = 0; i < towns_count; i++) {
        if (strcmp(towns[i].name, name) == 0)
            return &towns[i];
    }
    return &towns[0];
}

int main() {
    int towns_count;
    scanf("%d", &towns_count);
    town *towns = malloc(sizeof(town) * towns_count);

    for (int i = 0; i < towns_count; i++) {
        towns[i].name = malloc(sizeof(char) * MAX_STRING_LENGTH);
        scanf("%s", towns[i].name);
        scanf("%d", &towns[i].offices_count);
        towns[i].offices = malloc(sizeof(post_office) * towns[i].offices_count);
        for (int j = 0; j < towns[i].offices_count; j++) {
            scanf("%d%d%d", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
            towns[i].offices[j].packages = malloc(sizeof(package) * towns[i].offices[j].packages_count);
            for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
                towns[i].offices[j].packages[k].id = malloc(sizeof(char) * MAX_STRING_LENGTH);
                scanf("%s", towns[i].offices[j].packages[k].id);
                scanf("%d", &towns[i].offices[j].packages[k].weight);
            }
        }
    }

    int queries;
    scanf("%d", &queries);
    char town_name[MAX_STRING_LENGTH];

    while (queries--) {
        int type;
        scanf("%d", &type);
        switch (type) {
            case 1:
                scanf("%s", town_name);
                town *t = find_town(towns, towns_count, town_name);
                print_all_packages(*t);
                break;

            case 2:
                scanf("%s", town_name);
                town *source = find_town(towns, towns_count, town_name);
                int source_index;
                scanf("%d", &source_index);
                scanf("%s", town_name);
                town *target = find_town(towns, towns_count, town_name);
                int target_index;
                scanf("%d", &target_index);
                send_all_acceptable_packages(source, source_index, target, target_index);
                break;

            case 3:
                printf("Town with the most number of packages is %s\n", town_with_most_packages(towns, towns_count).name);
                break;
        }
    }

    return 0;
}
