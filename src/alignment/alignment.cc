/*
 * alignment.cc
 *
 *  Created on: Jan 17, 2016
 *      Author: isovic
 */

#include "alignment/alignment.h"


int AlignRegion(const SingleSequence *read, const Index *index, const ProgramParameters *parameters, const EValueParams *evalue_params, bool extend_to_end, PathGraphEntry *region_results) {

    if (parameters->alignment_algorithm == "gotoh") {
//      LogSystem::GetInstance().Log(VERBOSE_LEVEL_ALL_DEBUG, ((int64_t) read->get_sequence_id()) == parameters.debug_read, "Using semiglobal alignment approach.\n", "Alignment");
//      LogSystem::GetInstance().Log(VERBOSE_LEVEL_ALL_DEBUG, ((int64_t) read->get_sequence_id()) == parameters.debug_read, "Using Gotoh for alignment!\n", "Alignment");
//      if (region_results->get_region_data().is_split == false || parameters.is_reference_circular == false)
//        return LocalRealignmentLinear(SeqAnSemiglobalWrapperWithMyersLocalization, read, index, parameters, region_results, ret_alignment_position_left_part, ret_cigar_left_part, ret_AS_left_part, ret_nonclipped_left_part, ret_alignment_position_right_part, ret_cigar_right_part, ret_AS_right_part, ret_nonclipped_right_part, ret_orientation, ret_reference_id, ret_position_ambiguity, ret_eq_op, ret_x_op, ret_i_op, ret_d_op);
//      else
//        return LocalRealignmentCircular(SeqAnSemiglobalWrapperWithMyersLocalization, read, index, parameters, region_results, ret_alignment_position_left_part, ret_cigar_left_part, ret_AS_left_part, ret_nonclipped_left_part, ret_alignment_position_right_part, ret_cigar_right_part, ret_AS_right_part, ret_nonclipped_right_part, ret_orientation, ret_reference_id, ret_position_ambiguity, ret_eq_op, ret_x_op, ret_i_op, ret_d_op);

    } else if (parameters->alignment_algorithm == "myers") {

      LogSystem::GetInstance().Log(VERBOSE_LEVEL_ALL_DEBUG, ((int64_t) read->get_sequence_id()) == parameters->debug_read, "Using semiglobal alignment approach.\n", "Alignment");
      LogSystem::GetInstance().Log(VERBOSE_LEVEL_ALL_DEBUG, ((int64_t) read->get_sequence_id()) == parameters->debug_read, "Using Myers' bit-vector algorithm for alignment!\n", "Alignment");

      return SemiglobalAlignment(MyersSemiglobalWrapper, read, index, parameters, evalue_params, region_results);

//    } else if (parameters.alignment_algorithm == "anchor") {
//      LogSystem::GetInstance().Log(VERBOSE_LEVEL_ALL_DEBUG, ((int64_t) read->get_sequence_id()) == parameters.debug_read, "Using anchored alignment approach.\n", "Alignment");
//      bool is_linear = region_results->get_region_data().is_split == false || parameters.is_reference_circular == false;
//      LogSystem::GetInstance().Log(VERBOSE_LEVEL_ALL_DEBUG, ((int64_t) read->get_sequence_id()) == parameters.debug_read, "Using Myers' bit-vector algorithm for alignment!\n", "Alignment");
//      return AnchoredAlignment(is_linear, extend_to_end, MyersNWWrapper, MyersSHWWrapper, read, index, parameters, region_results, ret_alignment_position_left_part, ret_cigar_left_part, ret_AS_left_part, ret_nonclipped_left_part, ret_alignment_position_right_part, ret_cigar_right_part, ret_AS_right_part, ret_nonclipped_right_part, ret_orientation, ret_reference_id, ret_position_ambiguity, ret_eq_op, ret_x_op, ret_i_op, ret_d_op);
//
//    } else if (parameters.alignment_algorithm == "anchorgotoh") {
//      LogSystem::GetInstance().Log(VERBOSE_LEVEL_ALL_DEBUG, ((int64_t) read->get_sequence_id()) == parameters.debug_read, "Using anchored alignment approach.\n", "Alignment");
//      bool is_linear = region_results->get_region_data().is_split == false || parameters.is_reference_circular == false;
//      LogSystem::GetInstance().Log(VERBOSE_LEVEL_ALL_DEBUG, ((int64_t) read->get_sequence_id()) == parameters.debug_read, "Using Gotoh's algorithm for alignment!\n", "Alignment");
//      return AnchoredAlignment(is_linear, extend_to_end, SeqAnNWWrapper, SeqAnSHWWrapper, read, index, parameters, region_results, ret_alignment_position_left_part, ret_cigar_left_part, ret_AS_left_part, ret_nonclipped_left_part, ret_alignment_position_right_part, ret_cigar_right_part, ret_AS_right_part, ret_nonclipped_right_part, ret_orientation, ret_reference_id, ret_position_ambiguity, ret_eq_op, ret_x_op, ret_i_op, ret_d_op);
//
//#ifndef RELEASE_VERSION
//    } else if (parameters.alignment_algorithm == "anchormex") {
//      LogSystem::GetInstance().Log(VERBOSE_LEVEL_ALL_DEBUG, ((int64_t) read->get_sequence_id()) == parameters.debug_read, "Using anchored alignment approach.\n", "Alignment");
//      /// Extension to read ends is not currently supported. SHW alignment needs to be implemented in Opal first.
//      extend_to_end = false;
//      bool is_linear = region_results->get_region_data().is_split == false || parameters.is_reference_circular == false;
//      LogSystem::GetInstance().Log(VERBOSE_LEVEL_ALL_DEBUG, ((int64_t) read->get_sequence_id()) == parameters.debug_read, "Using Match Extend algorithm for alignment!\n", "Alignment");
//      return AnchoredAlignmentMex(is_linear, extend_to_end, OpalNWWrapper, OpalSHWWrapper, read, index, parameters, region_results, ret_alignment_position_left_part, ret_cigar_left_part, ret_AS_left_part, ret_nonclipped_left_part, ret_alignment_position_right_part, ret_cigar_right_part, ret_AS_right_part, ret_nonclipped_right_part, ret_orientation, ret_reference_id, ret_position_ambiguity, ret_eq_op, ret_x_op, ret_i_op, ret_d_op);
//#endif

    } else {
//      LogSystem::GetInstance().Log(VERBOSE_LEVEL_ALL_DEBUG, ((int64_t) read->get_sequence_id()) == parameters.debug_read, "Warning: Unknown alignment algorithm selected. Using Myers' bit-vector alignment instead.\n", "Alignment");
//      LogSystem::GetInstance().Log(VERBOSE_LEVEL_ALL_DEBUG, ((int64_t) read->get_sequence_id()) == parameters.debug_read, "Using semiglobal alignment approach.\n", "Alignment");
//      if (region_results->get_region_data().is_split == false || parameters.is_reference_circular == false)
//        return LocalRealignmentLinear(MyersSemiglobalWrapper, read, index, parameters, region_results, ret_alignment_position_left_part, ret_cigar_left_part, ret_AS_left_part, ret_nonclipped_left_part, ret_alignment_position_right_part, ret_cigar_right_part, ret_AS_right_part, ret_nonclipped_right_part, ret_orientation, ret_reference_id, ret_position_ambiguity, ret_eq_op, ret_x_op, ret_i_op, ret_d_op);
//      else
//        return LocalRealignmentCircular(MyersSemiglobalWrapper, read, index, parameters, region_results, ret_alignment_position_left_part, ret_cigar_left_part, ret_AS_left_part, ret_nonclipped_left_part, ret_alignment_position_right_part, ret_cigar_right_part, ret_AS_right_part, ret_nonclipped_right_part, ret_orientation, ret_reference_id, ret_position_ambiguity, ret_eq_op, ret_x_op, ret_i_op, ret_d_op);
      LogSystem::GetInstance().Log(VERBOSE_LEVEL_ALL_DEBUG, ((int64_t) read->get_sequence_id()) == parameters->debug_read, "Using semiglobal alignment approach (default).\n", "Alignment");
      LogSystem::GetInstance().Log(VERBOSE_LEVEL_ALL_DEBUG, ((int64_t) read->get_sequence_id()) == parameters->debug_read, "Using Myers' bit-vector algorithm for alignment!\n", "Alignment");

      return SemiglobalAlignment(MyersSemiglobalWrapper, read, index, parameters, evalue_params, region_results);
    }

  return -10;
}

void VerboseAlignment(const SingleSequence *read, const Index *index, const ProgramParameters *parameters, const AlignmentResults *aln) {
  if (parameters->verbose_level > 5 && read->get_sequence_id() == parameters->debug_read) {
    std::string alignment_as_string = "";

    alignment_as_string = PrintAlignmentToString((const unsigned char *) read->get_data(), read->get_sequence_length(),
       (const unsigned char *) (index->get_data() + aln->raw_pos_start), (aln->raw_pos_end - aln->raw_pos_start + 1),
       (unsigned char *) &(aln->raw_alignment[0]), aln->raw_alignment.size(),
       aln->raw_pos_end - aln->raw_pos_start, aln->aln_mode_code);
//       (aln->raw_pos_end - aln->aln_window_start), aln->aln_mode_code);

    LOG_DEBUG_SPEC("raw_pos_start = %ld\nraw_pos_end = %ld\nedit_distance = %ld\n",
       aln->raw_pos_start, aln->raw_pos_end, aln->edit_distance);
    LOG_DEBUG_SPEC("Alignment:\n%s\n",
       alignment_as_string.c_str());
    LOG_DEBUG_SPEC("\nref_start = %ld\nref_end = %ld\nraw_pos_start = %ld\nraw_pos_end = %ld\nquery_start = %ld\nquery_end = %ld\nreg_pos_start = %ld\reg_pos_end = %ld\norientation = %s\n",
                   aln->ref_start, aln->ref_end, aln->raw_pos_start, aln->raw_pos_end, aln->query_start, aln->query_end, aln->reg_pos_start, aln->reg_pos_end, (aln->orientation == kForward) ? "fwd" : "rev");
  }
}

/// Determines the start and end locations for semiglobal alignment locally to within the region. Region coordinates will be known from outside.
int GetL1PosInRegion(const SingleSequence *read, const Index *index, const ProgramParameters *parameters, const PathGraphEntry *region_results,
                     int64_t *l1_start, int64_t *l1_end) {
  const Region &region = region_results->get_region_data();

  SeqOrientation orientation = (region_results->get_region_data().reference_id >= index->get_num_sequences_forward()) ? (kReverse) : (kForward);
  int64_t abs_ref_id = region_results->get_region_data().reference_id;
  int64_t ref_start = index->get_reference_starting_pos()[abs_ref_id];
  int64_t ref_length = index->get_reference_lengths()[abs_ref_id];

  int64_t l1_ref_start = 0, l1_ref_end = 0, reference_data_length = 0;

  if (region.is_split == false || parameters->is_reference_circular == false) {
    l1_ref_start = region_results->get_l1_data().l1_lmin;
    l1_ref_end = ((int64_t) (region_results->get_l1_data().l1_k * read->get_sequence_length())) + region_results->get_l1_data().l1_lmax;

    /// Check the bounds.
    if (l1_ref_start < ref_start)
      l1_ref_start = ref_start;
    if (l1_ref_end >= (ref_start + ref_length))
      l1_ref_end = ref_start + ref_length - 1;

    reference_data_length = l1_ref_end - l1_ref_start + 1;

    *l1_start = l1_ref_start - region.start;
    *l1_end = l1_ref_end - region.start;

  } else {
    l1_ref_start = region_results->get_l1_data().l1_lmin;
    l1_ref_end = ((int64_t) (region_results->get_l1_data().l1_k * read->get_sequence_length())) + region_results->get_l1_data().l1_lmax;
    int64_t region_length_joined = (region.end - region.start + 1) + (region.split_end - region.split_start + 1);

    /// Check the bounds.
    if (l1_ref_start < 0)
      l1_ref_start = 0;
    if (l1_ref_end >= region_length_joined)
      l1_ref_end = region_length_joined - 1;

    reference_data_length = l1_ref_end - l1_ref_start + 1;

    *l1_start = l1_ref_start;
    *l1_end = l1_ref_end;
  }

  /// Debug output.
  if (parameters->verbose_level > 5 && read->get_sequence_id() == parameters->debug_read) {
    LOG_DEBUG_SPEC("\nread_length = %ld\nreference_length = %ld\nl1_start = %ld\nl1_end = %ld\nreference_data_length = %ld\nreference_start = %ld\nreference_length = %ld\nabsolute_reference_id = %ld\norientation = %s\n\n",
              read->get_sequence_length(), ref_length, l1_ref_start, l1_ref_end, reference_data_length, ref_start, ref_length, abs_ref_id, ((orientation == kForward) ? "forward" : "reverse"));
    LOG_DEBUG_SPEC("\n%s\n", region_results->VerboseInfoToString().c_str());
  }

  return 0;
}

///// Determines the start and end locations for semiglobal alignment, keeping in mind the boundaries of the reference being aligned to. Works with circular alignment as well.
//int GetAlignmentWindowFromRegion(const SingleSequence *read, const Index *index, const ProgramParameters *parameters, const PathGraphEntry *region_results,
//                                 int64_t *win_start, int64_t *win_end, int64_t *win_len) {
//  const Region &region = region_results->get_region_data();
//
//  SeqOrientation orientation = (region_results->get_region_data().reference_id >= index->get_num_sequences_forward()) ? (kReverse) : (kForward);
//  int64_t abs_ref_id = region_results->get_region_data().reference_id;
//  int64_t ref_start = index->get_reference_starting_pos()[abs_ref_id];
//  int64_t ref_length = index->get_reference_lengths()[abs_ref_id];
//
//  int64_t l1_ref_start = 0, l1_ref_end = 0, reference_data_length = 0;
//
//  if (region.is_split == false || parameters->is_reference_circular == false) {
//    l1_ref_start = region_results->get_l1_data().l1_lmin;
//    l1_ref_end = ((int64_t) (region_results->get_l1_data().l1_k * read->get_sequence_length())) + region_results->get_l1_data().l1_lmax;
//
//    /// Check the bounds.
//    if (l1_ref_start < ref_start)
//      l1_ref_start = ref_start;
//    if (l1_ref_end >= (ref_start + ref_length))
//      l1_ref_end = ref_start + ref_length - 1;
//
//    reference_data_length = l1_ref_end - l1_ref_start + 1;
//
//    *win_start = l1_ref_start;
//    *win_end = l1_ref_end;
//    *win_len = reference_data_length;
//  } else {
//    l1_ref_start = region_results->get_l1_data().l1_lmin;
//    l1_ref_end = ((int64_t) (region_results->get_l1_data().l1_k * read->get_sequence_length())) + region_results->get_l1_data().l1_lmax;
//    int64_t region_length_joined = (region.end - region.start + 1) + (region.split_end - region.split_start + 1);
//
//    /// Check the bounds.
//    if (l1_ref_start < 0)
//      l1_ref_start = 0;
//    if (l1_ref_end >= region_length_joined)
//      l1_ref_end = region_length_joined - 1;
//
//    reference_data_length = l1_ref_end - l1_ref_start + 1;
//
//    *win_start = l1_ref_start;
//    *win_end = l1_ref_end;
//    *win_len = reference_data_length;
//  }
//
//  /// Debug output.
//  if (parameters->verbose_level > 5 && read->get_sequence_id() == parameters->debug_read) {
//    LOG_DEBUG_SPEC("\nread_length = %ld\nreference_length = %ld\nl1_reference_start = %ld\nl1_reference_end = %ld\nreference_data_length = %ld\nreference_start = %ld\nreference_length = %ld\nabsolute_reference_id = %ld\norientation = %s\n\n",
//              read->get_sequence_length(), ref_length, l1_ref_start, l1_ref_end, reference_data_length, ref_start, ref_length, abs_ref_id, ((orientation == kForward) ? "forward" : "reverse"));
//    LOG_DEBUG_SPEC("\n%s\n", region_results->VerboseInfoToString().c_str());
//  }
//
//  return 0;
//}

//int GetAlignmentWindowData(const SingleSequence *read, const Index *index, const ProgramParameters *parameters, const PathGraphEntry *region_results,
//                           int8_t** data, int64_t* data_length, int8_t **pos_of_win_start, int8_t **pos_of_win_end, int64_t* offset_from_ref_start, int64_t* pos_of_ref_end, bool *is_cleanup_required) {
//  const Region &region = region_results->get_region_data();
//  int64_t ref_start = index->get_reference_starting_pos()[region.reference_id];
//
//  /// Calculate te offset for the L1 region filtering. This function considers whether the region was linear or circular.
//  int64_t win_start = 0, win_end = 0, win_len = 0;
//  GetAlignmentWindowFromRegion(read, index, parameters, region_results, &win_start, &win_end, &win_len);
//
//  if (region.is_split == false) {
//    *data = (int8_t *) index->get_data();
//    *pos_of_win_start = (int8_t *) index->get_data() + win_start;
//    *pos_of_win_end = (int8_t *) index->get_data() + win_end;
//    *offset_from_ref_start = (win_start - ref_start);
//    *data_length = region.end - region.start + 1;
//    *pos_of_ref_end = -1;
//    *is_cleanup_required = false;
//
//    return 0;
//
//  } else {
//    int64_t region_length_first = (region.end - region.start + 1);
//    int64_t region_length_second = (region.split_end - region.split_start + 1);
//    int64_t region_length_joined = region_length_first + region_length_second;
//
//    if (region_length_first <= 0 || region_length_second <= 0)
//      return 2;
//
//    int8_t *data_copy = (int8_t *) malloc(sizeof(int8_t) * (region_length_joined + 1));
//    if (data_copy == NULL) {
//      return 3;
//    }
//
//    int64_t start_offset = 0;
//    int64_t position_of_ref_end = 0;
//
//    // If the main region is at the beginning of the reference. The region is then expanded towards left and right, but on the left it zips back
//    // to the end of the circular reference.
//    if (region.start < region.split_start) {
//      memmove(data_copy, &(index->get_data()[region.split_start]), region_length_second);
//      memmove((data_copy + region_length_second), &(index->get_data()[region.start]), region_length_first);
//      position_of_ref_end = region.split_end - region.split_start; // The distance from the beginning of the region to the end of the chunk before the reference end.
//      start_offset = region.split_start;
//
//      // If the main region is at the end of the reference. The region is then expanded towards left and right, but on the right it zips back
//      // to the beginning of the circular reference.
//    } else {
//      memmove((data_copy), &(index->get_data()[region.start]), region_length_first);
//      memmove((data_copy + region_length_first), &(index->get_data()[region.split_start]), region_length_second);
//      position_of_ref_end = region.end - region.start; // The distance from the beginning of the region to the end of the chunk before the reference end.
//      start_offset = region.start;
//    }
//
//    data_copy[region_length_joined] = '\0';
//
//    *data = data_copy;
//    *pos_of_win_start = data_copy + win_start;
//    *pos_of_win_end = data_copy + win_end;
//    *data_length = region_length_joined;
//    *offset_from_ref_start = start_offset - ref_start;
//    *pos_of_ref_end = position_of_ref_end;
//    *is_cleanup_required = true;
//
//    LOG_DEBUG_SPEC("region_length_joined = %ld\n", region_length_joined);
//    LOG_DEBUG_SPEC("win_start = %ld\n", win_start);
//    LOG_DEBUG_SPEC("win_end = %ld\n", win_end);
//    LOG_DEBUG_SPEC("pos_of_win_start = %ld\n", (int64_t) *pos_of_win_start);
//    LOG_DEBUG_SPEC("pos_of_win_end = %ld\n", (int64_t) *pos_of_win_end);
//    LOG_DEBUG_SPEC("region.start = %ld\n", region.start);
//    LOG_DEBUG_SPEC("region.end = %ld\n", region.end);
//    LOG_DEBUG_SPEC("region.split_start = %ld\n", region.split_start);
//    LOG_DEBUG_SPEC("region.split_end = %ld\n", region.split_end);
//    LOG_DEBUG_SPEC("index.get_data_length() = %ld\n", index->get_data_length());
////    LOG_DEBUG_SPEC("\n%s\n", (char *) GetSubstring((char *) *pos_of_win_start, (win_end - win_start)).c_str());
//
//    return 0;
//  }
//
//  return 0;
//}

int FindCircularEnd(const std::vector<uint8_t> &alignment, int64_t pos_of_ref_end,
                    int64_t *ret_end_on_aln, int64_t *ret_end_on_read, int64_t *ret_end_on_ref,
                    int64_t *ret_start_on_aln, int64_t *ret_start_on_read, int64_t *ret_start_on_ref) {
  if (pos_of_ref_end < 0) return 1;

  int64_t pos_on_ref = 0, pos_on_read = 0;
  for (int64_t i=0; i<alignment.size(); i++) {
    if (alignment[i] == EDLIB_S) {
      pos_on_read += 1;
    } else if (alignment[i] == EDLIB_M || alignment[i] == EDLIB_EQUAL || alignment[i] == EDLIB_X) {
      pos_on_read += 1;
      pos_on_ref += 1;
      if (pos_on_ref == pos_of_ref_end) {
        *ret_end_on_ref = pos_on_ref;
        *ret_end_on_read = pos_on_read;
        *ret_end_on_aln = i;
      } else if (pos_on_ref > pos_of_ref_end) {
        *ret_start_on_ref = pos_on_ref;
        *ret_start_on_read = pos_on_read;
        *ret_start_on_aln = i;
        break;
      }
    } else if (alignment[i] == EDLIB_I) {
      pos_on_read += 1;
    } else if (alignment[i] == EDLIB_D) {
      pos_on_ref += 1;
    }
  }

  return 0;
}



//Ovo je iz GenerateAlignments_:     primary_alignment.pos_start = relative_position_left_part + 1;
//Sto znaci da cu to trebati handleati drukcije drugdje, prilikom zapisa SAM filea!

