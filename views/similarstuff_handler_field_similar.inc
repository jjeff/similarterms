<?php
// $Id: views_handler_field_counter.inc,v 1.3.2.2 2009/11/06 18:19:40 merlinofchaos Exp $

class similarstuff_handler_field_similar extends views_handler_field {
  function option_definition() {
    $options = parent::option_definition();
    //$options['counter_start'] = array('default' => 1);
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    /*
    $form['counter_start'] = array(
      '#type' => 'textfield',
      '#title' => t('Starting value'),
      '#default_value' => $this->options['counter_start'],
      '#description' => t('Specify the number the counter should start at.'),
      //'#process' => array('views_process_dependency'),
      '#size' => 2,
    );
    */
  }

  function query() {
    // do nothing -- to override the parent query.
  }

  function render($values) {
    return $values->node_count;
  }
}