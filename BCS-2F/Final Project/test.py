import xlsxwriter

def generate_excel():
    wb = xlsxwriter.Workbook("hello.xlsx")
    ws = wb.add_worksheet()
    ws.write('A1', 'Hello from Python!')
    wb.close()

if __name__ == "__main__":
    generate_excel()