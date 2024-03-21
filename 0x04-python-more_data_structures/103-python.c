#include <stdio.h>
#include <Python.h>

/**
 * print_python_bytes_info - Prints bytes information
 *
 * @bytes_obj: Python Bytes Object
 * Return: no return
 */
void print_python_bytes_info(PyObject *bytes_obj)
{
    char *string;
    long int size, i, limit;

    printf("[.] bytes object info\n");
    if (!PyBytes_Check(bytes_obj))
    {
        printf("  [ERROR] Invalid Bytes Object\n");
        return;
    }

    size = ((PyVarObject *)(bytes_obj))->ob_size;
    string = ((PyBytesObject *)bytes_obj)->ob_sval;

    printf("  size: %ld\n", size);
    printf("  trying string: %s\n", string);

    if (size >= 10)
        limit = 10;
    else
        limit = size + 1;

    printf("  first %ld bytes:", limit);

    for (i = 0; i < limit; i++)
        if (string[i] >= 0)
            printf(" %02x", string[i]);
        else
            printf(" %02x", 256 + string[i]);

    printf("\n");
}

/**
 * print_python_list_info - Prints list information
 *
 * @list_obj: Python List Object
 * Return: no return
 */
void print_python_list_info(PyObject *list_obj)
{
    long int size, i;
    PyListObject *list;
    PyObject *obj;

    size = ((PyVarObject *)(list_obj))->ob_size;
    list = (PyListObject *)list_obj;

    printf("[*] Python list info\n");
    printf("[*] Size of the Python List = %ld\n", size);
    printf("[*] Allocated = %ld\n", list->allocated);

    for (i = 0; i < size; i++)
    {
        obj = ((PyListObject *)list_obj)->ob_item[i];
        printf("Element %ld: %s\n", i, ((obj)->ob_type)->tp_name);
        if (PyBytes_Check(obj))
            print_python_bytes_info(obj);
    }
}

