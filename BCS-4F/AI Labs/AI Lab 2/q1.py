class Vehicle:
    def __init__(self, vehicle_id, brand, rent_per_day):
        self.vehicle_id = vehicle_id
        self.brand = brand
        self.rent_per_day = rent_per_day

    def display_details(self):
        print(f"Vehicle ID: {self.vehicle_id}")
        print(f"Brand: {self.brand}")
        print(f"Rent per day: RS {self.rent_per_day}")

    def calculate_rent(self, days):
        print(f"Total Rent For {self.brand} with ID {self.vehicle_id} for {days} Days: {self.rent_per_day * days}")


vehicle1 = Vehicle(1, "BMW", 24000)
vehicle2 = Vehicle(2, "Huawei", 20000)
vehicle1.display_details()
print("=========================================================")
vehicle2.display_details()
print("==========================================================")
vehicle1.calculate_rent(5)
print("==========================================================")
vehicle2.calculate_rent(5)
