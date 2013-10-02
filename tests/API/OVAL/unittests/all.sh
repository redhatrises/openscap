#!/bin/bash

. $srcdir/../../../test_common.sh

assert_exists() {
        real_cnt="$($XPATH $result 'count('"$2"')')"
        if [ "$real_cnt" != "$1" ]; then
                echo "Failed: expected count: $1, real count: $real_cnt, xpath: '$2'"
                return 1
        fi
}
export -f assert_exists

test_init test_api_oval_unittests.log
test_run "empty filename(pattern match)" $srcdir/test_empty_filename.sh
test_run "deprecated definition" $srcdir/test_deprecated_def.sh
test_run "applicability_check element" $srcdir/test_applicability_check.sh
test_run "count function"  $srcdir/test_count_function.sh
test_run "partial matches"  $srcdir/test_item_not_exist.sh
test_run "empty variable evaluation" $srcdir/test_oval_empty_variable_evaluation.sh
test_run "export of xsi:nil on pid entity of env.var.58_object" $srcdir/test_xsinil_envv58_pid.sh
test_run "anyxml element" $srcdir/test_anyxml.sh
test_exit
