#!/usr/bin/python3
"""Defines a locked class"""

class LockedClass:
    """
    This locked class will take ONLY attributes called 'first_name'
    """

    __slots__ = ['first_name']
