#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    float temperature;
    float rainfall;
    float wind_speed;
} WeatherForecast;

typedef struct {
    char crop_type[30];
    int growth_stage;
    float expected_yield;
    WeatherForecast *weather_forecast;
} Crop;

typedef struct {
    char equipment_type[30];
    char operational_status[15];
    float fuel_level;
    char activity_schedule[50];
} Equipment;

typedef struct {
    float soil_nutrients;
    float pH_level;
    float pest_activity;
} SensorData;

typedef struct {
    float latitude;
    float longitude;
    float soil_health_metric;
    float moisture_level;
    Crop *crops;             
    int crop_count;         
    Equipment *equipment;   
    int equipment_count;    
    SensorData *sensors;   
    int sensor_count;      
} Field;
Field create_field(float latitude, float longitude, float soil_health, float moisture, int crop_count) {
    Field field;
    field.latitude = latitude;
    field.longitude = longitude;
    field.soil_health_metric = soil_health;
    field.moisture_level = moisture;
    field.crops = (Crop *)malloc(sizeof(Crop) * crop_count);
    field.crop_count = crop_count;
    return field;
}

void input_crop_data(Crop *crop) {
    printf("Enter crop type: ");
    scanf("%s", crop->crop_type);

    printf("Enter growth stage (integer): ");
    scanf("%d", &crop->growth_stage);

    printf("Enter expected yield (float): ");
    scanf("%f", &crop->expected_yield);

    crop->weather_forecast = (WeatherForecast *)malloc(sizeof(WeatherForecast));
    printf("Enter weather forecast (temperature, rainfall, wind speed): ");
    scanf("%f %f %f", &crop->weather_forecast->temperature, &crop->weather_forecast->rainfall, &crop->weather_forecast->wind_speed);
}
void free_field(Field *field) {
	int i;
    for (i = 0; i < field->crop_count; i++) {
        free(field->crops[i].weather_forecast);
    }
    free(field->crops);
}
void search_crop(Field field, const char *crop_type) {
    int found = 0;
    int i;
    for (i=0; i<field.crop_count; i++) {
        if (strcmp(field.crops[i].crop_type, crop_type) == 0) {
            found = 1;
            printf("\nCrop Details:\n");
            printf("Crop Type: %s\n", field.crops[i].crop_type);
            printf("Growth Stage: %d\n", field.crops[i].growth_stage);
            printf("Expected Yield: %.2f\n", field.crops[i].expected_yield);
            printf("Weather Forecast:\n");
            printf("  Temperature: %.2f°C\n", field.crops[i].weather_forecast->temperature);
            printf("  Rainfall: %.2fmm\n", field.crops[i].weather_forecast->rainfall);
            printf("  Wind Speed: %.2fm/s\n", field.crops[i].weather_forecast->wind_speed);
            break;
        }
    }
    if (!found) {
        printf("Crop '%s' not found.\n", crop_type);
    }
}
int main() {
    int crop_count;
    int i;
    printf("Enter the number of crops in the field: ");
    scanf("%d", &crop_count);
    Field field = create_field(40.7128, -74.0060, 80.0, 50.0, crop_count);
    for (i = 0; i < crop_count; i++) {
        printf("\nEntering details for crop %d:\n", i + 1);
        input_crop_data(&field.crops[i]);
    }
    char search_type[30];
    printf("\nEnter the crop type to search for: ");
    scanf("%s", search_type);
    search_crop(field, search_type);
    free_field(&field);
    return 0;
}
