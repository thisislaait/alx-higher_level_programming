#include <Python.h>

/**
 * print_python_list - Prints basic information about Python lists.
 * @p: A PyObject list object.
 */
void print_python_list(PyObject *p) {
    Py_ssize_t size, i;
    const char *type;
    PyListObject *list = (PyListObject *)p;
    PyVarObject *var = (PyVarObject *)p;

    size = var->ob_size;

    printf("[*] Python list info\n");
    if (!PyList_Check(p)) {
        printf("  [ERROR] Invalid List Object\n");
        return;
    }

    printf("[*] Size of the Python List = %ld\n", size);

    printf("[*] Elements:\n");
    for (i = 0; i < size; i++) {
        type = Py_TYPE(list->ob_item[i])->tp_name;
        printf("Element %ld: %s\n", i, type);
    }
}

/**
 * print_python_bytes - Prints basic information about Python byte objects.
 * @p: A PyObject byte object.
 */
void print_python_bytes(PyObject *p) {
    Py_ssize_t size, i;
    PyBytesObject *bytes = (PyBytesObject *)p;

    printf("[.] bytes object info\n");
    if (!PyBytes_Check(p)) {
        printf("  [ERROR] Invalid Bytes Object\n");
        return;
    }

    size = ((PyVarObject *)p)->ob_size;
    printf("  size: %ld\n", size);

    printf("  trying string: %s\n", PyUnicode_DecodeEscape(bytes->ob_sval, size, "utf-8", NULL));

    printf("  first %ld bytes: ", (size > 10) ? 10 : size);
    for (i = 0; i < ((size > 10) ? 10 : size); i++) {
        printf("%02hhx", bytes->ob_sval[i]);
        if (i == (((size > 10) ? 10 : size) - 1))
            printf("\n");
        else
            printf(" ");
    }
}

/**
 * print_python_float - Prints basic information about Python float objects.
 * @p: A PyObject float object.
 */
void print_python_float(PyObject *p) {
    PyFloatObject *float_obj = (PyFloatObject *)p;

    printf("[.] float object info\n");
    if (!PyFloat_Check(p)) {
        printf("  [ERROR] Invalid Float Object\n");
        return;
    }

    printf("  value: %f\n", float_obj->ob_fval);
}
