from ctypes import memmove
import uuid

class MenuItem:
    def __init__(self, name, price, category, modifiers=None):
        self.id = str(uuid.uuid4())
        self.name = name
        self.price = price
        self.category = category  
        self.modifiers = modifiers if modifiers else []
    
    def __repr__(self):
        return f"MenuItem({self.name}, ${self.price}, {len(self.modifiers)} modifiers)"


class Menu:
    def __init__(self, name, items=None):
        self.name = name
        self.items = items if items else []

    def get_items_by_category(self, category):
        return [item for item in self.items if item.category == category]
    
    def __repr__(self):
        return f"Menu({self.name}, {len(self.items)} items)"


class Modifier:
    def __init__(self, id, name, price, category):
        self.id = id
        self.name = name
        self.price = price
        self.category = category
    
    def __repr__(self):
        return f"Modifier({self.name}, ${self.price}, {self.category})"


external_menu= {
    "name": "The Daily Grind Cafe",
    "menu_items": [
        {
            "name": "Cappuccino",
            "base_price": 4.50,
            "category": "beverages",
            "modifiers": [
                "a1b2c3d4-e5f6-7890-abcd-ef1234567890",  
                "b2c3d4e5-f6a7-8901-bcde-f12345678901",  
                "c3d4e5f6-a7b8-9012-cdef-123456789012"
            ]
        },
        {
            "name": "Avocado Toast",
            "base_price": 8.99,
            "category": "food",
            "modifiers": [
                "a7b8c9d0-e1f2-3456-abcd-567890123456"
            ]
        },
        {
            "name": "Green Smoothie",
            "base_price": 6.50,
            "category": "beverages",
            "modifiers": [
                "a1b2c3d4-e5f6-7890-abcd-ef1234567890"
            ]
        },
        {
            "name": "Caesar Salad",
            "base_price": 9.99,
            "category": "food",
            "modifiers": [
                "f2a3b4c5-d6e7-8901-fabc-012345678901",  
                "a3b4c5d6-e7f8-9012-abcd-123456789012"
            ]
        }
    ],
    "modifiers": [
        {"id": "a1b2c3d4-e5f6-7890-abcd-ef1234567890", "name": "Small", "price": 0.0, "category": "size"},
        {"id": "b2c3d4e5-f6a7-8901-bcde-f12345678901", "name": "Medium", "price": 0.50, "category": "size"},
        {"id": "c3d4e5f6-a7b8-9012-cdef-123456789012", "name": "Large", "price": 1.00, "category": "size"},
        {"id": "d4e5f6a7-b8c9-0123-defa-234567890123", "name": "Extra Shot", "price": 0.75, "category": "extra"},
        {"id": "e5f6a7b8-c9d0-1234-efab-345678901234", "name": "Oat Milk", "price": 0.60, "category": "milk"},
        {"id": "f6a7b8c9-d0e1-2345-fabc-456789012345", "name": "Almond Milk", "price": 0.60, "category": "milk"},
        {"id": "a7b8c9d0-e1f2-3456-abcd-567890123456", "name": "Add Egg", "price": 2.00, "category": "extra"},
        {"id": "b8c9d0e1-f2a3-4567-bcde-678901234567", "name": "Add Bacon", "price": 2.50, "category": "extra"},
        {"id": "c9d0e1f2-a3b4-5678-cdef-789012345678", "name": "Gluten Free Bread", "price": 1.50, "category": "dietary"},
        {"id": "d0e1f2a3-b4c5-6789-defa-890123456789", "name": "Protein Powder", "price": 1.00, "category": "extra"},
        {"id": "e1f2a3b4-c5d6-7890-efab-901234567890", "name": "Chia Seeds", "price": 0.50, "category": "extra"},
        {"id": "f2a3b4c5-d6e7-8901-fabc-012345678901", "name": "Add Chicken", "price": 3.00, "category": "protein"},
        {"id": "a3b4c5d6-e7f8-9012-abcd-123456789012", "name": "Add Shrimp", "price": 4.50, "category": "protein"},
        {"id": "b4c5d6e7-f8a9-0123-bcde-234567890123", "name": "Extra Dressing", "price": 0.50, "category": "extra"},
        {"id": "c5d6e7f8-a9b0-1234-cdef-345678901234", "name": "No Croutons", "price": 0.0, "category": "dietary"}
    ]
}

def construct_modifier_lookup(modifiers):
    lookup = {}
    for modifier in modifiers:
        modifier_id = modifier["id"]
        modifier_name = modifier["name"]
        modifier_price = modifier["price"]
        modifier_category = modifier["category"]
        
        # map modifier string to type Modifier
        lookup[modifier_id] =  Modifier(modifier_id, modifier_name, modifier_price, modifier_category)
    return lookup


def construct_menu(external_menu) -> Menu:
    external_menu_name = external_menu.get("name", "Unamed Menu")
    external_menu_items = external_menu.get("menu_items", []) 
    external_menu_modifiers = external_menu.get("modifiers", [])
    lookUp = construct_modifier_lookup(external_menu_modifiers)
    
    items = list()
    # process menu items
    for menu_item in external_menu_items:
        item_name = menu_item["name"]
        item_base_price = menu_item["base_price"]
        item_category = menu_item["category"]
        item_modifiers = menu_item["modifiers"]

        modifiers = list()
        add_ons = 0
        for modifier in item_modifiers:
            modifier_obj = lookUp[modifier]
            add_ons += modifier_obj.price
            modifiers.append(modifier_obj)

        total_item_price = item_base_price + add_ons
        menu_item_obj = MenuItem(item_name, total_item_price, item_category, modifiers)
        items.append(menu_item_obj)
    
    menu = Menu(external_menu_name, items)
    return menu



import unittest
class TestConstructMenu(unittest.TestCase):
    
    def test_basic_menu_construction(self):
        """Test Case 1: Basic menu construction with valid data"""
        menu = construct_menu(external_menu)
        
        # Verify menu name
        self.assertEqual(menu.name, "The Daily Grind Cafe")
        
        # Verify number of items
        self.assertEqual(len(menu.items), 4)
        
        # Verify item names
        item_names = [item.name for item in menu.items]
        self.assertIn("Cappuccino", item_names)
        self.assertIn("Avocado Toast", item_names)
        self.assertIn("Green Smoothie", item_names)
        self.assertIn("Caesar Salad", item_names)
    
    
    def test_modifiers_correctly_linked(self):
        """Test Case 2: Verify modifiers are correctly linked to menu items"""
        menu = construct_menu(external_menu)
        
        # Find Cappuccino
        cappuccino = next(item for item in menu.items if item.name == "Cappuccino")
        
        # Verify number of modifiers
        self.assertEqual(len(cappuccino.modifiers), 3)
        
        # Verify modifier names
        modifier_names = [mod.name for mod in cappuccino.modifiers]
        self.assertIn("Small", modifier_names)
        self.assertIn("Medium", modifier_names)
        self.assertIn("Large", modifier_names)
        
        # Verify modifier prices
        small_modifier = next(mod for mod in cappuccino.modifiers if mod.name == "Small")
        self.assertEqual(small_modifier.price, 0.0)
    
    
    def test_shared_modifiers(self):
        """Test Case 3: Verify same modifier is shared between items"""
        menu = construct_menu(external_menu)
        
        # Get Cappuccino and Green Smoothie
        cappuccino = next(item for item in menu.items if item.name == "Cappuccino")
        smoothie = next(item for item in menu.items if item.name == "Green Smoothie")
        
        # Both have "Small" modifier with id "a1b2c3d4-e5f6-7890-abcd-ef1234567890"
        cap_small = next(mod for mod in cappuccino.modifiers if mod.id == "a1b2c3d4-e5f6-7890-abcd-ef1234567890")
        smoothie_small = next(mod for mod in smoothie.modifiers if mod.id == "a1b2c3d4-e5f6-7890-abcd-ef1234567890")
        
        # Should be the same object (shared reference)
        self.assertIs(cap_small, smoothie_small)
    
    
    def test_category_filtering(self):
        """Test Case 4: Test get_items_by_category method"""
        menu = construct_menu(external_menu)
        
        # Get beverages
        beverages = menu.get_items_by_category("beverages")
        self.assertEqual(len(beverages), 2)
        beverage_names = [item.name for item in beverages]
        self.assertIn("Cappuccino", beverage_names)
        self.assertIn("Green Smoothie", beverage_names)
        
        # Get food items
        food_items = menu.get_items_by_category("food")
        self.assertEqual(len(food_items), 2)
        food_names = [item.name for item in food_items]
        self.assertIn("Avocado Toast", food_names)
        self.assertIn("Caesar Salad", food_names)
        
        # Get non-existent category
        desserts = menu.get_items_by_category("desserts")
        self.assertEqual(len(desserts), 0)
    
    
    def test_missing_modifier_id(self):
        """Test Case 5: Handle missing modifier ID gracefully"""
        invalid_menu = {
            "name": "Test Cafe",
            "menu_items": [
                {
                    "name": "Coffee",
                    "base_price": 3.00,
                    "category": "beverages",
                    "modifiers": ["invalid-modifier-id-12345"]  # Non-existent ID
                }
            ],
            "modifiers": [
                {"id": "valid-id-123", "name": "Sugar", "price": 0.0, "category": "sweetener"}
            ]
        }
        
        # Should raise KeyError or handle gracefully
        with self.assertRaises(KeyError):
            construct_menu(invalid_menu)


class TestEdgeCases(unittest.TestCase):
    
    def test_empty_menu(self):
        """Test Case 6: Empty menu with no items"""
        empty_menu = {
            "name": "Empty Cafe",
            "menu_items": [],
            "modifiers": []
        }
        
        menu = construct_menu(empty_menu)
        self.assertEqual(len(menu.items), 0)
        self.assertEqual(menu.name, "Empty Cafe")
    
    
    def test_item_with_no_modifiers(self):
        """Test Case 7: Menu item with no modifiers"""
        simple_menu = {
            "name": "Simple Cafe",
            "menu_items": [
                {
                    "name": "Black Coffee",
                    "base_price": 2.00,
                    "category": "beverages", 
                    "modifiers": []  # No modifiers
                }
            ],
            "modifiers": [
                {"id": "mod-1", "name": "Sugar", "price": 0.0, "category": "sweetener"}
            ]
        }
        
        menu = construct_menu(simple_menu)
        coffee = menu.items[0]
        self.assertEqual(len(coffee.modifiers), 0)
        self.assertEqual(coffee.name, "Black Coffee")


if __name__ == '__main__':
    unittest.main()



