#if !defined FAT_SHORTEN_FIELDS_H
#define FAT_SHORTEN_FIELDS_H

#define _FAT_HEX_SIGNATURE_ARRAY_NAME HexSignatureArray

#define _FAT_PREV_ITEM_ADD_SZ(_item) \
    _FAT_ITEM_ID_ ## _item ## _SZ + _FAT_ITEM_ID_ ## _item ## _IDX

#define __FAT_FIELD_GENERATE( \
    _name, \
    _index, \
    _size, \
    _flags_StructEnd, \
    _flags_BufEnd \
) \
    ._name = { \
        .field = &_FAT_HEX_SIGNATURE_ARRAY_NAME[_index], \
        .size = _size, \
        .index = _index, \
        .flags = { \
            .StructEnd = _flags_StructEnd, \
            .BufferEnd = _flags_BufEnd, \
        } \
    }

#define _FAT_FIELD_GENERATE_ONLY_FIELD2( \
    _name, \
    _index, \
    _size, \
    ... \
) \
    __FAT_FIELD_GENERATE( \
        _name, \
        _index, \
        _size, \
        __VA_ARGS__ \
    )


#define _FAT_FIELD_GENERATE_NULL(_xEnd, _aEnd) \
    __FAT_FIELD_GENERATE_ONLY_FIELD2( \
        FAT_ITEM_ID_ ## _NULL ## _NAME, \
        FAT_ITEM_ID_ ## _NULL ## _IDX, \
        FAT_ITEM_ID_ ## _NULL ## _SZ, \
\
        _xEnd, \
        _aEnd \
    )

#define fatFIELD_ITEM_ID_INIT(_field) \
    _FAT_FIELD_GENERATE_ONLY_FIELD2( \
        FAT_ITEM_ID_ ## _field ## _NAME, \
        FAT_ITEM_ID_ ## _field ## _IDX, \
        FAT_ITEM_ID_ ## _field ## _SZ, \
        0, \
        0 \
    )

#define fatFIELD_ITEM_ID_INIT_NULL() \
    _FAT_FIELD_GENERATE_NULL(1, 0)

#define fat_FIELD_ITEM_ID_INIT_GENERAL_NULL() \
    _FAT_FIELD_GENERATE_NULL(1, 1)

#endif /*FAT_SHORTEN_FIELDS_H */