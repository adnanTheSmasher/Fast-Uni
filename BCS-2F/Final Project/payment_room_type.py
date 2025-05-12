import sys
from openpyxl import load_workbook

def get_room_type(room_number, sheet):
    
    for row in sheet.iter_rows(min_row=2, values_only=True):  
        if row[0] == room_number: 
            return row[1]  
    return "Room number not found"

def main():
    if len(sys.argv) != 2:
        print("Error invalid argv")
        sys.exit(1)

    try:
        room_number = int(sys.argv[1])
        
        # Load the Excel file (make sure the file is in the same directory or provide the full path)
        workbook = load_workbook('record.xlsx')
        sheet = workbook.active
        
        # Get the room type based on the room number
        room_type = get_room_type(room_number, sheet)
        print(room_type)

    except ValueError:
        print("Please enter a valid room number.")
        sys.exit(1)

if __name__ == "__main__":
    main()
