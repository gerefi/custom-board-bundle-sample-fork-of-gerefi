# Warnings-as-errors...
gerefi_OPT = -Werror

# ...except these few
gerefi_OPT += -Wno-error=unused-function -Wno-error=unused-variable -Wno-error=sign-compare -Wno-error=unused-parameter
