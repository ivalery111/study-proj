
inches_to_meters=lambda x:x*0.0254
inches_to_feets=lambda x:x/12
miles_to_feets=lambda x:5280*x
composition=lambda f,g:lambda x: g(f(x))
opposite=lambda x:lambda y:y**2/x(y)
feets_to_inches = opposite(inches_to_feets)
miles_to_inches = composition(feets_to_inches, miles_to_feets)
meters_to_inches=opposite(inches_to_meters)
miles_to_meters=composition(inches_to_meters,miles_to_inches)
inches_to_miles=opposite(miles_to_inches)
feets_to_miles=opposite(miles_to_feets)
feets_to_meters=composition(inches_to_meters,feets_to_inches)
meters_to_miles=opposite(miles_to_meters)
meters_to_feets=opposite(feets_to_meters)

class Meters():
    """meters class has an  attribute of it's type and the next functionality:
        __init__:that inisilizing the value of the instance
        str and repr
    """
    def __init__(self,value):
        if type(value)==float or type(value)==int:
            self.value=float(value)
        elif type(value)==str:
            value2=value.split()
            if value2[1]!='m':
                raise Exception('Format error:{}'.format(value))
            self.value=float(value2[0])
        else:
            raise TypeError("Type error:{}".format(type(value)))
    def __str__(self):
        return '{} m'.format(self.value)
    def __repr__(self):
        return 'Meters({})'.format(self.value)

class Inches():
    """Inches class has  the next functionality:
        __init__:that inisilizing the value of the instance
        str and repr
    """
    def __init__(self,value):
        if type(value)==float or type(value)==int:
            self.value=float(value)
        elif type(value)==str:
            value2=value.split()
            if value2[1]!='in':
                raise Exception('Format error:{}'.format(value))
            self.value=float(value2[0])
        else:
            raise TypeError("Type error:{}".format(type(value)))
    def __str__(self):
        return '{} in'.format(self.value)
    def __repr__(self):
        return 'Inches({})'.format(self.value)

#part2 q2
### Our custom OOP

def make_class(attrs, base=None):
    """Return a new class (a dispatch dictionary) with given class attributes"""

    # Getter: class attribute (looks in this class, then base)
    def get(name):
        if name in attrs:
            return attrs[name]
        elif base:
            return base['get'](name)

    # Setter: class attribute (always sets in this class)
    def set(name, value):
        attrs[name] = value

    # Return a new initialized object instance (a dispatch dictionary)
    def new(*args):
        # instance attributes (hides encapsulating function's attrs)
        attrs = {}

        # Getter: instance attribute (looks in object, then class (binds self if callable))
        def get(name):
            if name in attrs:
                return attrs[name]
            else:
                value = cls['get'](name)
                if callable(value):
                    return lambda *args: value(obj, *args)
                else:
                    return value

        # Setter: instance attribute (always sets in object)
        def set(name, value):
            attrs[name] = value

        # instance dictionary
        obj = {'get': get, 'set': set}

        # calls constructor if present
        init = get('__init__')
        if init: init(*args)

        return obj

    # class dictionary
    cls = {'get': get, 'set': set, 'new': new}
    return cls

def make_feets_class():
    """feets class has an  attribute of it's type and the next functionality:
        __init__:that inisilizing the value of the instance
        str and repr
    """
    __type__='Feets'
    def __init__(self,value):
        if type(value)==float or type(value)==int:
            self['set']('value',float(value))
        elif type(value)==str:
            value2=value.split()
            if value2[1]!='ft':
                raise Exception('Format error:{}'.format(value))
            self['set']('value',float(value2[0]))
        else:
            raise TypeError("Type error:{}".format(type(value)))
    def __str__(self):
        return '{} ft'.format(self['get']('value'))
    def __repr__(self):
        return "Feets['new']({})".format(self['get']('value'))   
    return make_class(locals())

def make_miles_class():
    """miles class has an  attribute of it's type and the next functionality:
        __init__:that inisilizing the value of the instance
        str and repr
    """
    __type__='Miles'
    def __init__(self,value):
        if type(value)==float or type(value)==int:
            self['set']('value',float(value))
        elif type(value)==str:
            value2=value.split()
            if value2[1]!='mi':
                raise Exception('Format error:{}'.format(value))
            self['set']('value',float(value2[0]))
        else:
            raise TypeError("Type error:{}".format(type(value)))
    def __str__(self):
        return '{} mi'.format(self['get']('value'))
    def __repr__(self):
        return "Miles['new']({})".format(self['get']('value'))   
    return make_class(locals())

Feets = make_feets_class()
Miles= make_miles_class()

def to_str(f):
    """function that recives an object of spython or python and returns it's textual represention"""
    return f['get']('__str__')() if type(f)==dict else str(f) 
def to_repr(f):
    """function that recives an object of spython or python and returns it's repr represention"""
    return f['get']('__repr__')() if type(f)==dict else  repr(f)
def type_of(f):
    """function that recives an object of spython or python and returns it's type"""
    return f['get']('__type__') if type(f)==dict else type(f) 


def type_tag(x):
    """Return the tag associated with type of x."""
    return type_tag.tags[type_of(x)]
type_tag.tags = {Meters: 'm', Inches: 'in', 'Feets' :  'ft', 'Miles' : 'mi'}
def apply(op_name, a, b):
    """Applt function to do a operator oveloading"""
    tags = (type_tag(a), type_tag(b))
    if op_name == '-':op_name = 'sub'
    elif op_name == '+':op_name = 'add'
    elif op_name=='==':op_name='eq'
    elif op_name=='>':op_name='gt'
    key = (op_name, tags)
    return apply.implementations[key](a, b)


#Apply functions
# arithmetics#
#add
add_Inches= lambda x,y: Inches(x.value + y.value)
add_Inches_to_Feets = lambda x,y: Inches(x.value + feets_to_inches(y['get']('value')))
add_Inches_to_Meters= lambda x,y: Inches(x.value + meters_to_inches(y.value))
add_Inches_to_Miles = lambda x,y: Inches(x.value + miles_to_inches(y['get']('value')))
add_Feets_to_Inches= lambda x,y: Feets['new'](x['get']('value') + inches_to_feets(y.value))
add_Feets_to_Feets= lambda x,y: Feets['new'](x['get']('value') + y['get']('value'))
add_Feets_to_Meters= lambda x,y: Feets['new'](x['get']('value') + meters_to_feets(y.value))
add_Feets_to_Miles= lambda x,y: Feets['new'](x['get']('value') + miles_to_feets(y['get']('value')))
add_Miles_to_Inches = lambda x,y: Miles['new'](x['get']('value') + inches_to_miles(y.value))
add_Miles_to_Feets = lambda x,y: Miles['new'](x['get']('value') + feets_to_miles(y['get']('value')))
add_Miles_to_Meters= lambda x,y: Miles['new'](x['get']('value') + meters_to_miles(y.value))
add_Miles= lambda x,y: Miles['new'](x['get']('value') + y['get']('value'))
add_Meters_to_Inches= lambda x,y: Meters(x.value + inches_to_meters(y.value))
add_Meters_to_Feets= lambda x,y: Meters(x.value + feets_to_meters(y['get']('value')))
add_Meters= lambda x,y: Meters(x.value + y.value)
add_Meters_to_Miles = lambda x,y: Meters(x.value + miles_to_meters(y['get']('value')))
#sub
sub_Inches = lambda x,y: Inches(x.value - y.value)
sub_Inches_to_Feets= lambda x,y: Inches(x.value - feets_to_inches(y['get']('value')))
sub_Inches_to_Meters = lambda x,y: Inches(x.value - meters_to_inches(y.value))
sub_Inches_to_Miles = lambda x,y: Inches(x.value - miles_to_inches(y['get']('value')))
sub_Feets_to_Inches= lambda x,y: Feets['new'](x['get']('value') - inches_to_feets(y.value))
sub_Feets= lambda x,y: Feets['new'](x['get']('value') - y['get']('value'))
sub_Feets_to_Meters= lambda x,y: Feets['new'](x['get']('value') - meters_to_feets(y.value))
sub_Feets_to_Miles = lambda x,y: Feets['new'](x['get']('value') - miles_to_feets(y['get']('value')))
sub_Miles_to_Inches = lambda x,y: Miles['new'](x['get']('value') - inches_to_miles(y.value))
sub_Miles_Feets = lambda x,y: Miles['new'](x['get']('value') - feets_to_miles(y['get']('value')))
sub_Miles_Meters = lambda x,y: Miles['new'](x['get']('value') - meters_to_miles(y.value))
sub_Miles = lambda x,y: Miles['new'](x['get']('value') - y['get']('value'))
sub_Meters_Inches= lambda x,y: Meters(x.value - inches_to_meters(y.value))
sub_Meters_Feets = lambda x,y: Meters(x.value - feets_to_meters(y['get']('value')))
sub_Meters = lambda x,y: Meters(x.value - y.value)
sub_Meters_Miles= lambda x,y: Meters(x.value - miles_to_meters(y['get']('value')))
#logical
#>
gt_Inches = lambda x,y: x.value > y.value
gt_Inches_Feets= lambda x,y: x.value > feets_to_inches(y['get']('value'))
gt_Inches_Meters = lambda x,y: x.value > y.value
gt_Inches_Miles = lambda x,y: x.value > miles_to_inches(y['get']('value'))
gt_Feets_Inches = lambda x,y: x['get']('value') > inches_to_feets(y.value)
gt_Feets = lambda x,y: x['get']('value') > y['get']('value')
gt_Feets_to_Meters = lambda x,y: x['get']('value') > meters_to_feets(y.value)
gt_Feets_Miles = lambda x,y: x['get']('value') > miles_to_feets(y['get']('value'))
gt_Meters_Inches = lambda x,y: x.value > inches_to_meters(y.value)
gt_Meters_Feets = lambda x,y: x.value > feets_to_meters(y['get']('value'))
gt_Meters = lambda x,y: x.value > y.value
gt_Meters_Miles = lambda x,y: x.value > miles_to_meters(y['get']('value'))
gt_Miles_Inches = lambda x,y: x['get']('value') > inches_to_miles(y.value)
gt_Miles_Feets = lambda x,y: x['get']('value') > feets_to_miles(y['get']('value'))
gt_Miles_Meters = lambda x,y: x['get']('value') > meters_to_miles(y.value)
gt_Miles = lambda x,y: x['get']('value') > y['get']('value')
eq_Feets_Inches = lambda x,y: x['get']('value') == inches_to_feets(y.value)
eq_Feets = lambda x,y: x['get']('value') == y['get']('value')
eq_Feets_Meters = lambda x,y: x['get']('value') == meters_to_feets(y.value)
eq_Feets_Miles = lambda x,y: x['get']('value') == miles_to_feets(y['get']('value'))
eq_Meters_Inches = lambda x,y: x.value == inches_to_meters(y.value)
eq_Meters_Feets = lambda x,y: x.value == feets_to_meters(y['get']('value'))
eq_Meters = lambda x,y: x.value == y.value
eq_Meters_Miles = lambda x,y: x.value == miles_to_meters(y['get']('value'))
eq_Miles_Inches = lambda x,y: x['get']('value') == inches_to_miles(y.value)
eq_Miles_Feets = lambda x,y: x['get']('value') == feets_to_miles(y['get']('value'))
eq_Miles_Meters = lambda x,y: x['get']('value') == meters_to_miles(y.value)
eq_Miles = lambda x,y: x['get']('value') == y['get']('value')
eq_Inches = lambda x,y: x.value == y.value
eq_Inches_Feets = lambda x,y: x.value == feets_to_inches(y['get']('value'))
eq_Inches_Meters = lambda x,y: x.value == y.value
eq_Inches_Miles = lambda x,y: x.value == miles_to_inches(y['get']('value'))
#Apply dict:
apply.implementations = {('add',('in', 'in')):add_Inches,('add',('in', 'ft')):add_Inches_to_Feets,
                 ('add',('in', 'm')):add_Inches_to_Meters,('add',('in', 'mi')):add_Inches_to_Miles,
                 ('add',('ft', 'in')):add_Feets_to_Inches,('add',('ft', 'ft')):add_Feets_to_Feets,
                 ('add',('ft', 'm')):add_Feets_to_Meters,('add',('ft', 'mi')):add_Feets_to_Miles,
                 ('add',('mi', 'in')):add_Miles_to_Inches,('add',('mi', 'ft')):add_Miles_to_Feets,
                 ('add',('mi', 'm')):add_Miles_to_Meters,('add',('mi', 'mi')):add_Miles,
                 ('add',('m', 'in')):add_Meters_to_Inches,('add',('m', 'ft')):add_Meters_to_Feets,
                 ('add',('m', 'm')):add_Meters,('add',('m', 'mi')):add_Meters_to_Miles,
                 ('sub',('in', 'in')):sub_Inches,('sub',('in', 'ft')):sub_Inches_to_Feets,
                 ('sub',('in', 'm')):sub_Inches_to_Meters,('sub',('in', 'mi')):sub_Inches_to_Miles,
                 ('sub',('ft', 'in')):sub_Feets_to_Inches,('sub',('ft', 'ft')):sub_Feets,
                 ('sub',('ft', 'm')):sub_Feets_to_Meters,('sub',('ft', 'mi')):sub_Feets_to_Miles,('sub',('mi', 'in')):sub_Miles_to_Inches,
                 ('sub',('mi', 'ft')):sub_Miles_Feets,('sub',('mi', 'm')):sub_Miles_Meters,
                 ('sub',('mi', 'mi')):sub_Miles,('sub',('m', 'in')):sub_Meters_Inches,
                 ('sub',('m', 'ft')):sub_Meters_Feets,('sub',('m', 'm')):sub_Meters,
                 ('sub',('m', 'mi')):sub_Meters_Miles,('gt',('in', 'in')):gt_Inches,
                 ('gt',('in', 'ft')):gt_Inches_Feets,('gt',('in', 'm')):gt_Inches_Meters,('gt',('in', 'mi')):gt_Inches_Miles,
                 ('gt',('ft', 'in')):gt_Feets_Inches,('gt',('ft', 'ft')):gt_Feets,
                 ('gt',('ft', 'm')):gt_Feets_to_Meters,('gt',('ft', 'mi')):gt_Feets_Miles,
                 ('gt',('m', 'in')):gt_Meters_Inches,('gt',('m', 'ft')):gt_Meters_Feets,
                 ('gt',('m', 'm')):gt_Meters,('gt',('m', 'mi')):gt_Meters_Miles,
                 ('gt',('mi', 'in')):gt_Miles_Inches,('gt',('mi', 'ft')):gt_Miles_Feets,
                 ('gt',('mi', 'm')):gt_Miles_Meters,('gt',('mi', 'mi')):gt_Miles,
                 ('eq',('ft', 'in')):eq_Feets_Inches,('eq',('ft', 'ft')):eq_Feets,
                 ('eq',('ft', 'm')):eq_Feets_Meters,('eq',('ft', 'mi')):eq_Feets_Miles,
                 ('eq',('m', 'in')):eq_Meters_Inches,('eq',('m', 'ft')):eq_Meters_Feets,
                 ('eq',('m', 'm')):eq_Meters,('eq',('m', 'mi')):eq_Meters_Miles,
                 ('eq',('mi', 'in')):eq_Miles_Inches,('eq',('mi', 'ft')):eq_Miles_Feets,
                 ('eq',('mi', 'm')):eq_Miles_Meters,('eq',('mi', 'mi')):eq_Miles,
                 ('eq',('in', 'in')):eq_Inches,('eq',('in', 'ft')):eq_Inches_Feets,
                 ('eq',('in', 'm')):eq_Inches_Meters,('eq',('in', 'mi')):eq_Inches_Miles
                 
                 } 

coercions = {('in', 'm'): lambda x:Meters(inches_to_meters(x.value))}

def coerce_apply(operator_name, x, y):
    """
    function that doing operator overloading betewwn to different types by converting one to another
    """
    tx, ty = type_tag(x), type_tag(y)
    if tx != ty:
        if (tx, ty) in coercions:
            tx, x = ty, coercions[(tx, ty)](x)
        elif (ty, tx) in coercions:
            ty, y = tx, coercions[(ty, tx)](y)
        else:
            return 'No coercion possible.'
    assert tx == ty
    key = (operator_name, tx)
    return coerce_apply.implementations[key](x, y)
coerce_apply.implementations={('sub','m'):sub_Meters,('add','m'):add_Meters}
  



class ValueExistsException(Exception):
    """Exception class that throws an exception Value exists:
        for example 'Same Value Exists:10.0 m'
    """
    def __init__(self,x):self.x=x
    def __str__(self):
        return 'Same Value Exists:{}'.format(self.x)
    
    
class ValueNotExistsException(Exception):
     """Exception class that throws an exception Value not exists:
        for example 'Value Not Exists:10.0 m'
     """
     def __init__(self,x):self.x=x
     def __str__(self):
        return 'Value Not Exists:{}'.format(self.x)

class EmptyTreeException(Exception):
    """Exception class that throws an exception empty tree:
        for example 'The Tree Is Empty'
    """
    def __init__(self):pass
    def __str__(self):
        return 'The Tree Is Empty'
class TreeNode():
    """
    That class represents a Node of a tree
    the functionality is 
    __init__: that initilazing the attributes of an instance: left(that represents the left son of the node),right(that represents the right son of the node) and the key-value
    search: that searchs a node with a given value returns None if the value does not exists
    insert: inserts a given data the insertion works as insertion of a BST
    height: returns the height of the node
    delete: deletes a node
    successor:return the min of a subtree
    in_order:builds an in order list of the tree
    str and repr
    """
    
    def __init__(self,data):
        self.left=None
        self.right=None
        self.data=data
    def search(self,data):
        if not self:return None
        if apply('==',self.data,data):return self
        if apply('>',self.data,data):return self.left
        if not apply('>',self.data,data):return self.right      
    def insert(self,data):
        if apply('==',self.data,data):raise ValueExistsException(to_str(data))
        elif apply('>',self.data,data):
            if self.left:
                return self.left.insert(data)
            else:
                self.left=TreeNode(data)
                return self.left
        else:
            if self.right:
                return self.right.insert(data)
            else:
                self.right=TreeNode(data)
                return self.right
    @property 
    def height(self):
        if self.left and self.right:return 1+max(self.left.height,self.right.height)
        if self.left:return self.left.height+1
        if self.right:return self.right.height+1
        return 1
    def delete(self, data):
        if not self.search(data):raise ValueNotExistsException(data)
        if not self:return self
        if apply('>',self.data,data):
            if self.left:self.left = self.left.delete(data)
        elif not apply('==', data, self.data ):
            if self.right:self.right = self.right.delete(data)
        else:
            if not self.left:
                temp = self.right
                self = None
                return temp
            elif not self.right:
                temp = self.left
                self = None
                return temp
            temp = self.right.successor   
            self.data = temp.data
            self.right = self.right.delete(temp.data)
        return self
    @property 
    def successor(self):
        return self if not self.left else  self.left.successor
    
    def in_order(self,args):
        if self.left:self.left.in_order(args)
        args+=[self.data]
        if self.right:self.right.in_order(args)
        return args
    
    def __repr__(self):
        args=to_repr(self.data)
        if self.left or self.right:
            args+=',{},{}'.format(repr(self.left),repr(self.right))
        return '{}'.format(args)

    def __str__(self):
        if self.left and self.right:
            return 'TreeNode({}), Left = TreeNode({}),Right = TreeNode({})'.format(to_repr(self.data),str(self.left),str(self.right))
        elif self.left:
            return '{}, Left = TreeNode({})'.format(to_repr(self.data), str(self.left))
        elif self.right:
            return '{}, Right = TreeNode({})'.format(to_repr(self.data), str(self.right))
        else:
            return '{}'.format(to_repr(self.data))

class BSTree():
    """
    a class that represents a binary serch tree
    the functionality is 
    __init__: that initilazing the attributes of an instance: a root that initilized to none
    search: that searchs a node with a given value returns None if the value does not exists
    insert: inserts a given data the insertion works as insertion of a BST
    height: returns the height of the node
    delete: deletes a node
    in_order:builds an in order list of the tree
    str and repr
    """
    def __init__(self):
        self.root=None
    def search(self,data):
        return self.root.search(data)
    def insert(self,data):
        def insert_one(self,data):            
            try:
                if self.root:return self.root.insert(data)
                else:self.root=TreeNode(data)
            except ValueExistsException as e:print(e)
        if type(data) in (list,tuple):
            for v in data:insert_one(self,v)
        else:return insert_one(self,data)
            
    def __repr__(self):
        return "BSTree()" if not self.root else "BSTree("+repr(self.root)+")"
    def __str__(self):
        return "BSTree()" if not self.root  else "BSTree(" + str(self.root)+")"
    def delete(self,data):
        if not self.root:raise EmptyTreeException()
        elif type(data) in (list,tuple):
            for v in data:
                try:
                    self.root.delete(v)
                except ValueNotExistsException as e:print(e)
        else:
            try:
                self.root.delete(data)
            except ValueNotExistsException as e:print(e)
        return self.root
    
    def height(self):
        return self.root.height if self.root else None		
    def in_order(self):
        if not self.root:raise EmptyTreeException()
        args=[]
        if self.root:return self.root.in_order(args)
  
