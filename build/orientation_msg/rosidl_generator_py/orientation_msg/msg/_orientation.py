# generated from rosidl_generator_py/resource/_idl.py.em
# with input from orientation_msg:msg/Orientation.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Orientation(type):
    """Metaclass of message 'Orientation'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('orientation_msg')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'orientation_msg.msg.Orientation')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__orientation
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__orientation
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__orientation
            cls._TYPE_SUPPORT = module.type_support_msg__msg__orientation
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__orientation

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Orientation(metaclass=Metaclass_Orientation):
    """Message class 'Orientation'."""

    __slots__ = [
        '_acc_x',
        '_acc_y',
        '_acc_z',
        '_gyro_x',
        '_gyro_y',
        '_gyro_z',
        '_mag_x',
        '_mag_y',
        '_mag_z',
        '_lin_acc_x',
        '_lin_acc_y',
        '_lin_acc_z',
        '_quat_x',
        '_quat_y',
        '_quat_z',
        '_quat_w',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'acc_x': 'double',
        'acc_y': 'double',
        'acc_z': 'double',
        'gyro_x': 'double',
        'gyro_y': 'double',
        'gyro_z': 'double',
        'mag_x': 'double',
        'mag_y': 'double',
        'mag_z': 'double',
        'lin_acc_x': 'double',
        'lin_acc_y': 'double',
        'lin_acc_z': 'double',
        'quat_x': 'double',
        'quat_y': 'double',
        'quat_z': 'double',
        'quat_w': 'double',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.acc_x = kwargs.get('acc_x', float())
        self.acc_y = kwargs.get('acc_y', float())
        self.acc_z = kwargs.get('acc_z', float())
        self.gyro_x = kwargs.get('gyro_x', float())
        self.gyro_y = kwargs.get('gyro_y', float())
        self.gyro_z = kwargs.get('gyro_z', float())
        self.mag_x = kwargs.get('mag_x', float())
        self.mag_y = kwargs.get('mag_y', float())
        self.mag_z = kwargs.get('mag_z', float())
        self.lin_acc_x = kwargs.get('lin_acc_x', float())
        self.lin_acc_y = kwargs.get('lin_acc_y', float())
        self.lin_acc_z = kwargs.get('lin_acc_z', float())
        self.quat_x = kwargs.get('quat_x', float())
        self.quat_y = kwargs.get('quat_y', float())
        self.quat_z = kwargs.get('quat_z', float())
        self.quat_w = kwargs.get('quat_w', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.acc_x != other.acc_x:
            return False
        if self.acc_y != other.acc_y:
            return False
        if self.acc_z != other.acc_z:
            return False
        if self.gyro_x != other.gyro_x:
            return False
        if self.gyro_y != other.gyro_y:
            return False
        if self.gyro_z != other.gyro_z:
            return False
        if self.mag_x != other.mag_x:
            return False
        if self.mag_y != other.mag_y:
            return False
        if self.mag_z != other.mag_z:
            return False
        if self.lin_acc_x != other.lin_acc_x:
            return False
        if self.lin_acc_y != other.lin_acc_y:
            return False
        if self.lin_acc_z != other.lin_acc_z:
            return False
        if self.quat_x != other.quat_x:
            return False
        if self.quat_y != other.quat_y:
            return False
        if self.quat_z != other.quat_z:
            return False
        if self.quat_w != other.quat_w:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def acc_x(self):
        """Message field 'acc_x'."""
        return self._acc_x

    @acc_x.setter
    def acc_x(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'acc_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'acc_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._acc_x = value

    @builtins.property
    def acc_y(self):
        """Message field 'acc_y'."""
        return self._acc_y

    @acc_y.setter
    def acc_y(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'acc_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'acc_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._acc_y = value

    @builtins.property
    def acc_z(self):
        """Message field 'acc_z'."""
        return self._acc_z

    @acc_z.setter
    def acc_z(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'acc_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'acc_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._acc_z = value

    @builtins.property
    def gyro_x(self):
        """Message field 'gyro_x'."""
        return self._gyro_x

    @gyro_x.setter
    def gyro_x(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'gyro_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'gyro_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._gyro_x = value

    @builtins.property
    def gyro_y(self):
        """Message field 'gyro_y'."""
        return self._gyro_y

    @gyro_y.setter
    def gyro_y(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'gyro_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'gyro_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._gyro_y = value

    @builtins.property
    def gyro_z(self):
        """Message field 'gyro_z'."""
        return self._gyro_z

    @gyro_z.setter
    def gyro_z(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'gyro_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'gyro_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._gyro_z = value

    @builtins.property
    def mag_x(self):
        """Message field 'mag_x'."""
        return self._mag_x

    @mag_x.setter
    def mag_x(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'mag_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'mag_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._mag_x = value

    @builtins.property
    def mag_y(self):
        """Message field 'mag_y'."""
        return self._mag_y

    @mag_y.setter
    def mag_y(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'mag_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'mag_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._mag_y = value

    @builtins.property
    def mag_z(self):
        """Message field 'mag_z'."""
        return self._mag_z

    @mag_z.setter
    def mag_z(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'mag_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'mag_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._mag_z = value

    @builtins.property
    def lin_acc_x(self):
        """Message field 'lin_acc_x'."""
        return self._lin_acc_x

    @lin_acc_x.setter
    def lin_acc_x(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'lin_acc_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'lin_acc_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._lin_acc_x = value

    @builtins.property
    def lin_acc_y(self):
        """Message field 'lin_acc_y'."""
        return self._lin_acc_y

    @lin_acc_y.setter
    def lin_acc_y(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'lin_acc_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'lin_acc_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._lin_acc_y = value

    @builtins.property
    def lin_acc_z(self):
        """Message field 'lin_acc_z'."""
        return self._lin_acc_z

    @lin_acc_z.setter
    def lin_acc_z(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'lin_acc_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'lin_acc_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._lin_acc_z = value

    @builtins.property
    def quat_x(self):
        """Message field 'quat_x'."""
        return self._quat_x

    @quat_x.setter
    def quat_x(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'quat_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'quat_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._quat_x = value

    @builtins.property
    def quat_y(self):
        """Message field 'quat_y'."""
        return self._quat_y

    @quat_y.setter
    def quat_y(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'quat_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'quat_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._quat_y = value

    @builtins.property
    def quat_z(self):
        """Message field 'quat_z'."""
        return self._quat_z

    @quat_z.setter
    def quat_z(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'quat_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'quat_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._quat_z = value

    @builtins.property
    def quat_w(self):
        """Message field 'quat_w'."""
        return self._quat_w

    @quat_w.setter
    def quat_w(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'quat_w' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'quat_w' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._quat_w = value
