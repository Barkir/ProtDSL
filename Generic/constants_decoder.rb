GET_FIELD_CODE = <<~CODE
    uint32_t getField(uint32_t command, int32_t from, int32_t to, int32_t mask) {
        return (command >> from) & mask;
    }
CODE
