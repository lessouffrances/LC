from typing import Callable, List, Dict

class Column:
    def __init__(self, name: str, data: List[int]):
        self.name = name
        self.data = data
    
    def get_data(self) -> List[int]:
        return self.data

class DataWarehouseTable:
    def __init__(self, name: str, columns: List[Column]):
        self.name = name
        self.columns: Dict[str, Column] = { column.name: column for column in columns }
    
    def get_column(self, name: str) -> Column:
        if name not in self.columns:
            raise ValueError(f"No column found with the name: {name}")
        return self.columns[name]
    
class DataWarehouse:
    def __init__(self, tables: List[DataWarehouseTable]):
        self.tables : Dict[str, DataWarehouseTable] = { table.name: table for table in tables } 
    
    def get_table(self, name: str) -> DataWarehouseTable:
        if name not in self.tables:
            raise ValueError(f"No table found with the name: {name}")

class SigmaTable:
    def __init__(self, name: str, base_table_name: str, get_data_warehouse: Callable[[], DataWarehouse]):
        self.name = name
        self.base_table_name = base_table_name
        self.get_data_warehouse = get_data_warehouse
        
        
    def set_sum_col(self, col_name: str, left_col_name: str, right_col_name: str):
        pass

    def set_diff_col(self, col_name: str, left_col_name: str, right_col_name: str):
        pass

    def get_column(self, col_name: str) -> Column:
        pass

    def get_all_columns(self) -> Dict[str, Column]:
        pass

    def set_max_summary(self, summary_name: str, col_name: str):
        pass

    def set_min_summary(self, summary_name: str, col_name: str):
        pass

    def get_summaries(self) -> Dict[str, int]:
        pass

def make_test_table() -> SigmaTable:
    col1 = Column(name="col1", data=[1, 2, 3])
    col2 = Column(name="col2", data=[4, 5, 6])
    col3 = Column(name="col3", data=[7, 8])

    table1 = DataWarehouseTable(name="test_table_1", columns=[col1, col2, col3])

    warehouse = DataWarehouse(tables=[table1])
    sigma_table = SigmaTable(name="test_sigma_table", base_table_name = "test_table_1", get_data_warehouse=lambda: warehouse)

    return sigma_table

def pretty_print_table(sigma_table: SigmaTable):
    print("-- TABLE --" + "-" * 50)
    print(f"{sigma_table.name}, based on {sigma_table.base_table_name}")
    print("-- COLUMNS --" + "-" * 47)

    columns = sigma_table.get_all_columns()
    if not columns or len(columns) == 0:
        print("No columns found.")
    else:
        for col in columns:
            print(f"{col}: {columns[col].get_data()}")    
    print("-- SUMMARIES --" + "-" * 45)
    summaries = sigma_table.get_summaries()
    if not summaries or len(summaries.keys()) == 0:
        print("No summaries found.")
    else:
        for summary in summaries:
            print(f"{summary}: {summaries[summary]}")
    print("-" * 60)

def print_test():
    pretty_print_table(make_test_table())