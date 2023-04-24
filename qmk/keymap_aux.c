const key_override_t single_quote = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_QUOT);

const key_override_t double_quote = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_DQUO);

const key_override_t **key_overrides = (const key_override_t *[]){
    &single_quote,
    &double_quote,
    NULL // terminate the array of overrides
};
