def my_sum(a,b):
    '''sum two elements 
    examples:
    >>> my_sum(3,4)
    7
    
    >>> my_sum("one", "two")
    'onetwo'
    '''
    return a+b


if __name__== '__main__': #this executes the examples in the doc(?)
    
    import doctest      #doctest is standard
    doctest.testmod()
